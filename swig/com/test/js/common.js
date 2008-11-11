
var geos = WScript.CreateObject("geos.geos");

var results = "";

function assert(result, message) {
	if (result == false) {
		WScript.Echo("assert: " + message);
		results += "x";
	} else {
		results += "o";
	}
};

function assertEqual(expected, result, message) {
	if (expected != result) {
		WScript.Echo("assertEqual: " + message + "\n" + "expected:" + "\t" + expected + "\n" + "result:" + "\t" + result);
		results += "x";
	} else {
		results += "o";
	}
};

function report() {
	if (results.indexOf("x", 0) >= 0) {
		WScript.Echo("Failed! - " + results);
	} else {
		WScript.Echo("Succeeded! - " + results);
	}
	results = "";
};
