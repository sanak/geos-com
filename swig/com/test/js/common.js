
var geos = WScript.CreateObject("geos.geos");

var tests = WScript.CreateObject("Scripting.Dictionary");
var current = "";

function setup(name) {
	tests.Add(name, "");
	current = name;
};

function assert(result, message) {
	if (result == false) {
		tests(current) += "assert: " + message + "\n";
	}
};

function assertEqual(expected, result, message) {
	if (expected != result) {
		tests(current) += "assertEqual: " + message + "\n" + "expected:" + "\t" + expected + "\n" + "result:" + "\t" + result + "\n";
	}
};

function report() {
	var sum = 0;
	var failures = 0;
	var result = "";
	var message = "";
	var keys = tests.Keys().toArray();
	for (var i = 0; i < keys.length; i++) {
		var name = keys[i];
		sum += 1;
		if (tests(name).length > 0) {
			failures += 1;
			message += "\n" + tests(name);
			result += "F";
		} else {
			result += ".";
		}
	}
	result += message + "\n" + sum + " tests, " + failures + " failures";
	WScript.Echo(result);
	tests.RemoveAll();
};
