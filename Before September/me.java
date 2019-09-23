package com.primathon.in.oneshot.ui.main;

import android.Manifest;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.content.pm.PackageManager;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.hardware.display.DisplayManager;
import android.hardware.display.VirtualDisplay;
import android.media.ImageReader;
import android.media.MediaRecorder;
import android.media.ThumbnailUtils;
import android.media.projection.MediaProjection;
import android.media.projection.MediaProjectionManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.provider.MediaStore;
import android.provider.Settings;
import android.support.annotation.NonNull;
import android.support.annotation.RequiresApi;
import android.support.design.widget.Snackbar;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.DisplayMetrics;
import android.util.Log;
import android.util.SparseIntArray;
import android.view.Menu;
import android.view.MenuItem;
import android.view.Surface;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import com.primathon.in.oneshot.R;
import com.primathon.in.oneshot.ui.FloatingViewService;
import com.primathon.in.oneshot.ui.helper.FileUtil;
import com.primathon.in.oneshot.ui.utils.ServiceCallbacks;

import java.io.File;
import java.io.IOException;
import java.util.Date;

public class MainActivity extends AppCompatActivity implements ServiceCallbacks {
    private static final int CODE_DRAW_OVER_OTHER_APP_PERMISSION = 1000;
    private static final int REQUEST_PERMISSIONS = 1001;
    private static final int REQUEST_CODE = 1002;
    private static final int DISPLAY_WIDTH;
    private static final int DISPLAY_HEIGHT;
    private static final String TAG = "MainActivity";
    private MediaProjectionManager mProjectionManager;
    private MediaProjection mMediaProjection;
    private VirtualDisplay mVirtualDisplay;
    private MediaProjectionCallback mMediaProjectionCallback;
    private Button mToggleButton;
    private MediaRecorder mMediaRecorder;
    private int mScreenDensity;

    private boolean initiated = false;
    private boolean prepared = false;
    private boolean folderCreated = false;

    private long currentTimeMillis;


    // Image Reader
    private ImageReader mImageReader;
    private int imagesProduced;
    private long startTimeInMillis;
    private Handler mHandler = new Handler(Looper.getMainLooper());

    private static final SparseIntArray ORIENTATIONS = new SparseIntArray();
    static {
        DISPLAY_HEIGHT = MainActivity.getScreenHeight();
        DISPLAY_WIDTH = MainActivity.getScreenWidth();
        ORIENTATIONS.append(Surface.ROTATION_0, 90);
        ORIENTATIONS.append(Surface.ROTATION_90, 0);
        ORIENTATIONS.append(Surface.ROTATION_180, 270);
        ORIENTATIONS.append(Surface.ROTATION_270, 180);
    }
    private static final String appDirectoryName = "1 Shot";
    private File apkRootFolder;

    private FloatingViewService floatingViewService;
    private boolean bound = false;
    private Button khicho;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M && !Settings.canDrawOverlays(MainActivity.this)) {
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + getPackageName()));
            startActivityForResult(intent, CODE_DRAW_OVER_OTHER_APP_PERMISSION);
        }

        initView();

        // Screen capturing code starts from here.
        DisplayMetrics metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);
        mScreenDensity = metrics.densityDpi;
        mMediaRecorder = new MediaRecorder();
        mProjectionManager = (MediaProjectionManager) getSystemService(Context.MEDIA_PROJECTION_SERVICE);

        currentTimeMillis = System.currentTimeMillis();
        khicho.setVisibility(View.VISIBLE);

        khicho.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.WRITE_EXTERNAL_STORAGE)
                        != PackageManager.PERMISSION_GRANTED) {
                    requestRequiredPermissions();
                } else {
                    // Toast.makeText(MainActivity.this, "Permissions Granted 1", Toast.LENGTH_SHORT).show();
                    if(!folderCreated){
                        createApkFolder();
                    }
                    start();
                }
            }
        });
    }

    private void createApkFolder() {
        apkRootFolder = new File(Environment.getExternalStoragePublicDirectory(
                Environment.DIRECTORY_DCIM), appDirectoryName);
        if(!apkRootFolder.exists()) {
            boolean mkdirs = apkRootFolder.mkdirs();
            if (!mkdirs) {
                print("Folder not created");
            } else {
                folderCreated = true;
                print("Folder created successfully");
            }
        }
        else {
            print("Folder already exists");
        }
    }

//  .............................................................................................
//  ..................................DEBUG MESSAGE............................................
//  .............................................................................................

    private void print(String a){
        Log.d("#DEBUG", a);
    }
//  .............................................................................................
//  ..................................INITIALIZE VIEW............................................
//  .............................................................................................

    private void initView(){
        khicho = findViewById(R.id.khicho);
        mToggleButton = findViewById(R.id.button);
    }

//  .............................................................................................
//  ..................................DELETE SAVED VIDEOS............................................
//  .............................................................................................

    private void deleteIt(String path) throws IOException {
        /*File file = new File(path);
        boolean deleted = file.delete();
        if(!deleted){
            // deleted = file.getAbsoluteFile().delete();
            deleted = file.getCanonicalFile().delete();
            if(!deleted){
                getApplicationContext().deleteFile(file.getName());
            }
        }*/
    }

//  .............................................................................................
//  ..................................CONVERT AND SAVE Screenshot............................................
//  .............................................................................................

    private void convertSaveDelete(){
        Date d1 = new Date();

        String root = Environment.getExternalStoragePublicDirectory(Environment .DIRECTORY_DCIM)+"/"+ appDirectoryName + "/video.mp4";
        Bitmap bitmap = ThumbnailUtils.createVideoThumbnail(root, MediaStore.Images.Thumbnails.FULL_SCREEN_KIND);
        Date d2 = new Date();
        print("Total time convert: "+ (d2.getTime() - d1.getTime()));


//        String path = Environment.getExternalStoragePublicDirectory(Environment .DIRECTORY_DOWNLOADS) + "/Screenshot-"+System.currentTimeMillis()+".png";
//        FileUtil.getInstance().storeBitmap(bitmap, path);

        String path = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DCIM) +"/"+ appDirectoryName +"/Screenshot-"+System.currentTimeMillis()+".png";
        FileUtil.getInstance().storeBitmap(bitmap, path);

        Toast.makeText(MainActivity.this, path, Toast.LENGTH_LONG).show();
        // delete it
//        try {
//            deleteIt(root);
//
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
    }

//  .............................................................................................
//  ..................................SERVICE............................................
//  .............................................................................................


    private void startFloatingService(){
        Intent intent = new Intent(this, FloatingViewService.class);
        bindService(intent, serviceConnection, Context.BIND_AUTO_CREATE);
    }


    private ServiceConnection serviceConnection = new ServiceConnection() {
        @Override
        public void onServiceConnected(ComponentName className, IBinder service) {
            // cast the IBinder and get MyService instance
            FloatingViewService.LocalBinder binder = (FloatingViewService.LocalBinder) service;
            floatingViewService = binder.getService();
            bound = true;
            floatingViewService.setCallbacks(MainActivity.this); // register
        }

        @Override
        public void onServiceDisconnected(ComponentName arg0) {
            bound = false;
        }
    };

    @Override
    public void onStartTriggerFromService() {
        Log.d("SERVICE_TRIGGER", "START ");
    }

    @Override
    public void onStopTriggerFromService() {
        Log.d("SERVICE_TRIGGER", "STOP");
    }
//  .............................................................................................
//  ..................................onActivityResult............................................
//  .............................................................................................

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        Log.d(TAG, "onActivityResult: "+requestCode+" "+resultCode);

        if (requestCode != REQUEST_CODE) {
            Log.e(TAG, "Unknown request code: " + requestCode);
            return;
        }
        if (resultCode != RESULT_OK) {
            Toast.makeText(this,
                    "Screen Cast Permission Denied", Toast.LENGTH_SHORT).show();
            return;
        }

        mMediaProjectionCallback = new MediaProjectionCallback();
        mMediaProjection = mProjectionManager.getMediaProjection(resultCode, data);
        mMediaProjection.registerCallback(mMediaProjectionCallback, null);
        mVirtualDisplay = createVirtualDisplay();

        startMediaRecorder();
    }

//  .............................................................................................
//  ..................................MEDIA RECORDER............................................
//  .............................................................................................

    private void start(){
        Date d1 = new Date();
        Date d3 = new Date();
        if(!initiated){
            prepared = initRecorder();
        }
        if(prepared){
            shareScreen();
        }
        Date d2 = new Date();
        print("Total time: "+ (d2.getTime() - d1.getTime()));
        print("Total time initrecorder: "+ (d3.getTime() - d1.getTime()));
    }

    public void startMediaRecorder(){
        if (mMediaRecorder != null && prepared) {
            mMediaRecorder.start();
            new Handler().postDelayed(new Runnable() {
                @Override
                public void run() {
                    // Do something after 1s = 1000ms
                    Date d1 = new Date();
                    stopMediaRecorder();
                    stopScreenSharing();
                    convertSaveDelete();
                    initiated = true;
                    prepared  = initRecorder();
                    Date d2 = new Date();
                    print("Total time startMediaRecorder: " + (d2.getTime() - d1.getTime()));

                }
            }, 1);
        }
    }

    private void shareScreen() {
        if (mMediaProjection == null) {
            print("mMediaProject ko non kar rahe");
            startActivityForResult(mProjectionManager.createScreenCaptureIntent(), REQUEST_CODE);
            return;
        }
        mVirtualDisplay = createVirtualDisplay();
        startMediaRecorder();
    }

    private VirtualDisplay createVirtualDisplay() {
        return mMediaProjection.createVirtualDisplay("MainActivity",
                DISPLAY_WIDTH, DISPLAY_HEIGHT, mScreenDensity,
                DisplayManager.VIRTUAL_DISPLAY_FLAG_AUTO_MIRROR,
                mMediaRecorder.getSurface(), null /*Callbacks*/, null
                /*Handler*/);
    }

    private boolean initRecorder() {
        try {
            Date d1 = new Date();
            mMediaRecorder.setVideoSource(MediaRecorder.VideoSource.SURFACE);
            mMediaRecorder.setOutputFormat(MediaRecorder.OutputFormat.MPEG_4);
            mMediaRecorder.setOutputFile(Environment
                    .getExternalStoragePublicDirectory(Environment
                            .DIRECTORY_DCIM) + "/"+ appDirectoryName+"/video.mp4");
            mMediaRecorder.setVideoSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
            mMediaRecorder.setVideoEncoder(MediaRecorder.VideoEncoder.H264);
            mMediaRecorder.setVideoEncodingBitRate(1024 * 1000);
            mMediaRecorder.setVideoFrameRate(1000);
            int rotation = getWindowManager().getDefaultDisplay().getRotation();
            int orientation = ORIENTATIONS.get(rotation + 90);
            mMediaRecorder.setOrientationHint(orientation);
            Date d2 = new Date();
            mMediaRecorder.prepare();
            Date d3 = new Date();
            print("Total time mMediaRecorder.prepare: "+ (d3.getTime() - d2.getTime()));
            print("Total time initRecorder(): "+ (d3.getTime() - d1.getTime()));
            //Toast.makeText(MainActivity.this, "MediaRecorder Prepared", Toast.LENGTH_SHORT).show();

            return true;
        } catch (IllegalStateException e) {
            //Toast.makeText(MainActivity.this, "MediaRecorder Prepared IllegalStateException", Toast.LENGTH_SHORT).show();
            e.printStackTrace();
            return false;
        } catch (IOException e) {
            //Toast.makeText(MainActivity.this, "MediaRecorder Prepared IOException", Toast.LENGTH_SHORT).show();
            e.printStackTrace();
            return false;
        }
    }

    private class MediaProjectionCallback extends MediaProjection.Callback {
        @Override
        public void onStop() {
            stopMediaRecorder();
            mMediaProjection = null;
            stopScreenSharing();
        }
    }

    public void stopMediaRecorder() {
        if (mMediaRecorder != null){
            mMediaRecorder.stop();
            mMediaRecorder.reset();
        }
    }

    private void destroyMediaProjection() {
        if (mMediaProjection != null) {
            mMediaProjection.unregisterCallback(mMediaProjectionCallback);
            mMediaProjection.stop();
            mMediaProjection = null;
        }
        Log.i(TAG, "MediaProjection Stopped");
    }

    private void stopScreenSharing() {
        if (mVirtualDisplay == null) {
            return;
        }
        mVirtualDisplay.release();
        destroyMediaProjection();
    }

//  .............................................................................................
//  ..................................onStart.....................................................
//  .............................................................................................

//  .............................................................................................
//  ..................................onStop.....................................................
//  .............................................................................................

    @Override
    protected void onStop() {
        super.onStop();
        // Unbind from service
        if (bound) {
            floatingViewService.setCallbacks(null); // unregister
            unbindService(serviceConnection);
            bound = false;
        }
    }

//  .............................................................................................
//  ..................................onDestroy............................................
//  .............................................................................................

    @Override
    public void onDestroy() {
        super.onDestroy();
        destroyMediaProjection();
        try {
            String root = Environment.getExternalStoragePublicDirectory(Environment .DIRECTORY_DCIM)+"/"+ appDirectoryName + "/video.mp4";
            deleteIt(root);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

//  .............................................................................................
//  ..................................PERMISSIONS STARTS............................................
//  .............................................................................................

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,  @NonNull int[] grantResults) {
        if (requestCode == REQUEST_PERMISSIONS) {
            if ((grantResults.length > 0) && (grantResults[0]  == PackageManager.PERMISSION_GRANTED)){
                Toast.makeText(MainActivity.this, "Permissions Granted 2", Toast.LENGTH_SHORT).show();
                if(!folderCreated){
                    createApkFolder();
                }
                start();
            } else {
               requestSeekBar();
            }
        }
    }

    private void requestRequiredPermissions() {
        if (ActivityCompat.shouldShowRequestPermissionRationale(MainActivity.this, Manifest.permission.WRITE_EXTERNAL_STORAGE)) {
            requestSeekBar();
        } else{
            ActivityCompat.requestPermissions(this, new String[] {Manifest.permission.WRITE_EXTERNAL_STORAGE}, REQUEST_PERMISSIONS);
        }
    }

    private void requestSeekBar(){
        Snackbar.make(findViewById(android.R.id.content), R.string.label_permissions,
                Snackbar.LENGTH_INDEFINITE).setAction("ENABLE",
                new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        Intent intent = new Intent();
                        intent.setAction(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
                        intent.addCategory(Intent.CATEGORY_DEFAULT);
                        intent.setData(Uri.parse("package:" + getPackageName()));
                        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                        intent.addFlags(Intent.FLAG_ACTIVITY_NO_HISTORY);
                        intent.addFlags(Intent.FLAG_ACTIVITY_EXCLUDE_FROM_RECENTS);
                        startActivity(intent);
                    }
                }).show();
    }

    private boolean isOverlayAllow(){
        return Build.VERSION.SDK_INT < Build.VERSION_CODES.M || Settings.canDrawOverlays(MainActivity.this);
    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    private void askOverlayPermission(){
        if(!isOverlayAllow()){
            Intent intent = new Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION, Uri.parse("package:" + getPackageName()));
            startActivityForResult(intent, CODE_DRAW_OVER_OTHER_APP_PERMISSION);
        }
    }
//  .............................................................................................
//  ..................................DEFAULT SCREEN WITH AND HEIGHT.............................
//  .............................................................................................


    public static int getScreenWidth() {
        return Resources.getSystem().getDisplayMetrics().widthPixels;
    }

    public static int getScreenHeight() {
        return Resources.getSystem().getDisplayMetrics().heightPixels;
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

//  .............................................................................................
//  ..................................MENU.......................................................
//  .............................................................................................

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
