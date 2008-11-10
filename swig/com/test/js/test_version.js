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

function TestVersion() {
};

TestVersion.prototype.testVersions = function() {
		WScript.Echo("testVersions");
		
		assertEqual("3.0.0rc4-CAPI-1.3.3", geos.version(), "geos.version");
		assertEqual(3, geos.GEOS_VERSION_MAJOR, "geos.GEOS_VERSION_MAJOR");
		assertEqual(0, geos.GEOS_VERSION_MINOR, "geos.GEOS_VERSION_MINOR");
		assertEqual(1, geos.GEOS_VERSION_PATCH, "geos.GEOS_VERSION_PATCH");
		assertEqual("3.0.1", geos.GEOS_VERSION, "geos.GEOS_VERSION");
		assertEqual("1.7.1", geos.GEOS_JTS_PORT, "geos.GEOS_JTS_PORT");
		assertEqual(1, geos.GEOS_CAPI_VERSION_MAJOR, "geos.GEOS_CAPI_VERSION_MAJOR");
		assertEqual(4, geos.GEOS_CAPI_VERSION_MINOR, "geos.GEOS_CAPI_VERSION_MINOR");
		assertEqual(1, geos.GEOS_CAPI_VERSION_PATCH, "geos.GEOS_CAPI_VERSION_PATCH");
		
		report();
};

var test = new TestVersion();
test.testVersions();
