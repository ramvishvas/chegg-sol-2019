class Sphere{
	private radius;
	public Sphere(){
		this.radius = 0;
	}

	public Sphere(float r){
		this.return = r;
	}

	public void setRadius(float r) {
		this.radius = r;
	}

	public float getRadius(){
		return this.radius;
	}

	public float getArea(){
		return 4*Math.PI*radius*radius;
	}

	public float getVolume(){
		return (4.0/3)*Math.PI*radius*radius*radius;
	}
}
