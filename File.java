import java.io.IOException; 
import java.io.FileWriter; 
import java.io.FileNotFoundException; 
import java.io.FileReader; 
import java.util.Scanner;

class File 
{ 
    public static void main(String[] args) throws IOException 
    { 
        Scanner in = new Scanner(System.in);

        System.out.print("Enter Input File Name: ");
        String inp = in.next();

        System.out.print("Enter Output File Name: ");
        String out = in.next();

        in.close();

        // attach a file to FileWriter
        FileReader inpf = null;

        // check if File exists or not 
        try
        { 
            inpf = new FileReader(inp); 
        } 
        catch (FileNotFoundException fe) 
        { 
            System.out.println("File not found"); 
            return;
        }

        FileWriter outf = new FileWriter(out);

        // variable declaration 
        int character; 
        // read from FileReader till the end of file 
        // and print and write it to output file
        while ((character = inpf.read()) != -1)
        {
            System.out.print((char)character);
            outf.write((char)character); 
        }

        // close the file 
        inpf.close();
        outf.close();
    } 
}