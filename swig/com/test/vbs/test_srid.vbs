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

Class SridTest
	Sub testSrid()
		WScript.Echo "testSrid"
		
		Dim cs
		Set cs = geos.CoordinateSequence.new_CoordinateSequence(1, 2)
		cs.setX 0, 7
		cs.setY 0, 8
		
		Dim geom1
		Set geom1 = geos.createPoint(cs)
		geom1.setSRID 4326
		
		assertEqual 4326, geom1.getSRID, "geom1.getSRID"
		
		report
	End Sub

	Sub testWriteSrid()
		WScript.Echo "testWriteSrid"
		
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Dim geom
		Set geom = reader.read("POINT(7 8)")
		geom.setSRID 4326
		
		Dim writer
		Set writer = geos.WkbWriter.new_WkbWriter()
		' without srid
		writer.setIncludeSRID False
		Dim hex
		hex = writer.writeHex(geom)
		assertEqual "01010000000000000000001C400000000000002040", hex, "hex"
		
		' with srid
		writer.setIncludeSRID True
		hex = writer.writeHex(geom)
		assertEqual "0101000020E61000000000000000001C400000000000002040", hex, "hex"
		
		report
	End Sub

	Sub testRoundtripSrid()
		WScript.Echo "testRoundtripSrid"
		
		Dim reader
		Set reader = geos.WktReader.new_WktReader()
		Dim geom1
		Set geom1 = reader.read("POINT(7 8)")
		geom1.setSRID 4326
		assertEqual 4326, geom1.getSRID, "geom1.getSRID"
		
		Dim writer
		Set writer = geos.WkbWriter.new_WkbWriter()
		writer.setIncludeSRID True
		Dim hex
		hex = writer.writeHex(geom1)
		
		Set reader = Nothing
		Set reader = geos.WkbReader.new_WkbReader()
		Dim geom2
		Set geom2 = reader.readHex(hex)
		assertEqual 4326, geom2.getSRID, "geom2.getSRID"
		
		report
	End Sub

	Sub testReadSRID()
		WScript.Echo "testReadSRID"
		
		' srid=4326;POINT(7 8)
		Dim xdr
		xdr = "0101000020E61000000000000000001C400000000000002040"
		
		Dim reader
		Set reader = geos.WkbReader.new_WkbReader()
		Dim geom
		Set geom = reader.readHex(xdr)
		
		assertEqual 7, geom.getCoordSeq.getX(0), "geom.getCoordSeq.getX(0)"
		assertEqual 8, geom.getCoordSeq.getY(0), "geom.getCoordSeq.getY(0)"
		assertEqual 4326, geom.getSRID, "geom.getSRID"
		
		report
	End Sub
End Class

Dim test
Set test = new SridTest
test.testSrid
test.testWriteSrid
test.testRoundtripSrid
test.testReadSRID
