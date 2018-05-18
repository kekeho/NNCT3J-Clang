# 課題1
## ソースコード
```sh
#!/bin/sh
grep $1 teldata
```

# 課題2
## ソースコード
```sh
#!/bin/csh
if ( $# == 0 ) then
	echo "Usage: $0 filename"
	exit 1
else if ( -f $1 ) then
	echo "$1 is a reguler file"
else if ( -d $1) then
	echo "$1 is a directory"
else
	echo "$1 does not exist"
endif

```

# 課題3
## ソースコード
```sh
#!/bin/csh

if (-e "hoge.update") then
	echo "Update already"
else
	set dateval = `date '+%y%m%d'`	
	cp hoge hoge.$dateval && cp hoge hoge.update && cp /tmp/hogenew hoge
endif

```