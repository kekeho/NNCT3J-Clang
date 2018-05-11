# 課題1
存在しない場合は何も表示されない。

# 課題２
## 2-1
最初がinで最後がinの単語  
### コマンド
```sh
grep '^in.*in$' /usr/share/dict/words
```
### 実行結果
```
inchpin
indazin
indigotin
indirubin
indophenin
infraprotein
ingrain
inkstain
inosin
insulin
interbrain
interjoin
intermountain
intertwin
intervein
inulin
invein
invertin

```

## 2-2
最後がtionで終わる21文字の単語
### コマンド
```sh
grep '^.................tion$' /usr/share/dict/words
```

### 実行結果
```
constitutionalization
counterinterpretation
cryptocrystallization
deintellectualization
heterotransplantation
overindustrialization
protransubstantiation
```

## 2-3
最初がqで最後がnessの18文字の単語
### コマンド
```sh
grep '^q.............ness$' /usr/share/dict/words
```
### 実行結果
```
quicksilverishness
```

## 2-4
単語の途中にabcがはいっている単語
### コマンド
```sh
grep '.*abc.*' /usr/share/dict/words
```
### 実行結果
```
abcoulomb
Babcock
crabcatcher
dabchick
```

## 2-5
qで始まり、a/e/i/o/uがこの順番にはいっている単語
### コマンド
```sh
grep '^q.*a.*e.*i.*o.*u.*' /usr/share/dict/words
```

### 実行結果
```
quadragenarious
quadrigeminous
quadrigenarious
```

## 2-6
a/b/c/d/eがこの順番ではいっている単語
### コマンド
```sh
grep '.*a.*b.*c.*d.*e.*' /usr/share/dict/words
```
### 実行結果
```
abjectedness
aborticide
absconded
abscondedly
abscondence
absconder
abstractedness
ambuscade
ambuscader
amoebicide
bambocciade
carbacidometer
Cerambycidae
Oxylabracidae
```

## 2-7
自分でつくる  
自分の名前のhirokiから最後の文字を除いた文字が、この順番二はいっている単語をさがす
### コマンド
```sh
grep '.*h.*i.*r.*o.*k.*' /usr/share/dict/words
```
### 実行結果
```
hairlock
hairwork
handistroke
rhinoceroslike
shipbroken
shirlcock
```

	
