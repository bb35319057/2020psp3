# 課題1 レポート
35319057　吉田 龍生


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明

l.67 int型のiとresult=-1を定義

l.70 for文でiがsizeより大きくなるか等しくなるまで回す

l.71 もしデータの中のIDとkeyの値が一致すればresultの値をiにしてfor文を抜ける

l.78 resultの値を返す


l.86　int型のposとresult=-1を定義

l.92 while文でleftがrightより大きくなるまで繰り返す

l.93 pos1の値を定義

l.94 もしkeyがpos番目のIDと一致すれば、resultの値をposにしてwhlie文を抜ける

l.97 keyがpos番目のIDより値が大きければ、leftをpos+1とする

l.99 上記以外ならば、rightをpos-1とする

l.103 resultの値を返す



## 出力結果

```

```

## 修正履歴

