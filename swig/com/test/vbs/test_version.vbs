Option Explicit

Dim geos
Set geos = WScript.CreateObject("geos.geos")

Dim results
results = ""

Sub assert(result, message)
	If result = False Then
		WScript.Echo "assert: " & message
		results = results & "x"
	Else
		results = results & "o"
	End If
End Sub

Sub assertEqual(expected, result, message)
	If expected <> result Then
		WScript.Echo "assertEqual: " & message & vbCrLf & "expected:" & vbTab & CStr(expected) & vbCrLf & "result:" & vbTab & CStr(result)
		results = results & "x"
	Else
		results = results & "o"
	End If
End Sub

Sub report()
	If InStr(1, results, "x") > 0 Then
		WScript.Echo "Failed! - " & results
	Else
		WScript.Echo "Succeeded! - " & results
	End If
	results = ""
End Sub

Class TestVersion
	Sub testVersions()
		WScript.Echo "testVersions"
		
		assertEqual "3.0.0rc4-CAPI-1.3.3", geos.version, "geos.version"
		assertEqual 3, geos.GEOS_VERSION_MAJOR, "geos.GEOS_VERSION_MAJOR"
		assertEqual 0, geos.GEOS_VERSION_MINOR, "geos.GEOS_VERSION_MINOR"
		assertEqual 1, geos.GEOS_VERSION_PATCH, "geos.GEOS_VERSION_PATCH"
		assertEqual "3.0.1", geos.GEOS_VERSION, "geos.GEOS_VERSION"
		assertEqual "1.7.1", geos.GEOS_JTS_PORT, "geos.GEOS_JTS_PORT"
		assertEqual 1, geos.GEOS_CAPI_VERSION_MAJOR, "geos.GEOS_CAPI_VERSION_MAJOR"
		assertEqual 4, geos.GEOS_CAPI_VERSION_MINOR, "geos.GEOS_CAPI_VERSION_MINOR"
		assertEqual 1, geos.GEOS_CAPI_VERSION_PATCH, "geos.GEOS_CAPI_VERSION_PATCH"
		
		report
	End Sub
End Class

Dim test
Set test = new TestVersion
test.testVersions
