function parseSource(strValue){
	return strValue.split(' ');
}

function biuldDistributionArray(strValueArray){
	let a = 0, b = 0, c = 0, d = 0, f = 0;
	for (let i = 0; i < strValueArray.length; i++) 
	{
		if(Number(strValueArray[i]) >= 90) 
		{
			a += 1;
		}
		else if(Number(strValueArray[i]) >= 80) 
		{
			b += 1;
		}
		else if(Number(strValueArray[i]) >= 70) 
		{
			c += 1;
		}
		else if(Number(strValueArray[i]) >= 60) 
		{
			d += 1;
		}
		else {
			f += 1;
		}
	}

	return [a, b, c, d, f];
}

// testing
let myString = '45 78 98 83 86 99 59';

let myStringArray = parseSource(myString);
console.log("stringArray: ", myStringArray);

let scoreArray = biuldDistributionArray(myStringArray);
console.log("scoreArray : ",scoreArray);