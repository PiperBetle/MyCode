ls "" -i *.out -r | foreach {
	ren $_.FullName $_.FullName.Replace("1","2")
}