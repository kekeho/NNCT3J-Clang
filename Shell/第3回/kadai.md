# 課題1
## ソースコード
```sh
#!/bin/csh
#ファイルを今日の日付入りファイルにコピーするスクリプト

if ($# == 1) then
    set now = `date "+%Y%m%d"`
    cp $1 $1.${now}
    exit()
endif
echo "引数が足りないか、多すぎます"
exit(-1)
```

# 課題2
## ソースコード
```sh
#!/bin/csh
if($# == 1) then
    set filename = `echo $1 | awk '{sub(".tex","");print $0;}'`
    platex $filename.tex
    platex $filename.tex
    xdvi $filename.dvi
    exit()

endif
echo "引数が足りないか多すぎます"
exit(-1)
```

# 課題3
## 行数表示
### ソースコード
```sh
wc -l httpd-access.log.19 | awk '{print $1}'
```
### 実行結果
```
56382
```

## どこからアクセスがあったか
### ソースコード
```sh
cat httpd-access.log.19 | awk '{print $1}' | uniq > list_from
```

## Forbiddenリスト
### ソースコード
```sh
grep ".* .* .* .* .* .* .* .* 403" httpd-access.log.19 | uniq > list_403
```

# 課題4
## ソースコード
```sh
#!/bin/csh
cd ~/
touch ducash
echo "Your home directory du check" > ducash
echo "" >> ducash
du -s ./*/ >> ducash
mail -s "Subject: HomeDir du check" 15316@g.nagano-nct.ac.jp < ducash
rm ducash
```

# 課題5
## ソースコード
```sh
#!/bin/csh
convert -resize 600x $1 s$1
```