# 課題4 レポート
35319057 吉田 龍生

## 課題
本課題では、全国の県庁所在地の消費データを読み込み、ソートするプログラムを作成する。

1. 使用するデータ  
全国の県庁所在地の消費データは、consumption.csvに保存されている。consumption.csvには、csv形式で、以下のデータが含まれる。
- ID
- 市の眺め
- 世帯人員
- 食料合計
- 穀類
- 魚介類
- 肉類
- 乳卵類
- 野菜類
- 果物
- 調味料
- 菓子類
- 調理料理
- 飲料
- 酒類
- 外食

県庁所在地の消費データは、下記構造体の配列に読み込まれる。

```
typedef struct {
    int id;
    char name[19];  //  市の名前、UTF-8対応
    float members;  //  世帯人員
    int total;      //  食料合計
    int grain;      //  穀類
    int seafood;    //  魚介類
    int meat;       //  肉類
    int milk;       //  乳卵類
    int vegetable;  //  野菜類
    int fruit;      //  果物
    int seasoning;  //  調味料
    int snack;      //  菓子類
    int cocking;    //  調理料理
    int drink;      //  飲料
    int liquor;     //  酒類
    int eatout;     //  外食
} City;
```

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
(1) BubbuleSort: バブルソートを用いて、食料合計(total)でソートする。  
    [入力]  
    - City arrayCity[]: 都市別消費データの配列  
    - int size: 都市の数  

    [出力]  
    - City arrayCity[]: 食料合計でソートされた都市別消費データの配列  

    (2) QuickSort: クイックソートを用いて、魚介類(seafood)でソートする。  
    [入力]  
    - City arrayCity[]: 都市別消費データの配列
    - int left: ソート対象配列の左側index  
    - int right: ソート対象配列の右側index  

    [出力]  
    - City arrayCity[]: 食料合計でソートされた都市別消費データの配列  

3. 補助関数  
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の都市のデータを出力する。  
- PrintArray: すべての都市のデータを出力する  
- LoadData: 都市毎の消費データを読み込み、City型の配列に格納する。
- main: メイン関数。データのロード、ソート処理の呼出を行う。

4. チャレンジ問題  
以下のプログラムを作成する。  
(1) HeapSort: ヒープソートを用いて、肉類(meat)でソートする。(10点)  
    [入力]  
    - City arrayCity[]: 都市別消費データの配列  
    - int size: 都市の数  

    [出力]  
    - City arrayCity[]: 食料合計でソートされた都市別消費データの配列  

    (2) MergeSort: マージソートを用いて、酒類(liquor)でソートする。(10点)    
    [入力]  
    - City arrayCity[]: 都市別消費データの配列
    - int left: ソート対象配列の左側index  
    - int right: ソート対象配列の右側index

    [出力]  
    - City arrayCity[]: 食料合計でソートされた都市別消費データの配列  

    (3) 世帯人員、食料合計、穀類、魚介類など、5項目以上で長崎市の順位を求める。(10点)  

## ソースコードの説明



## 出力結果

```
--バブルソート--

l.82 int型のcnt,pos,City型のtmpを定義

l.86 cntが0ではないとき、以下を繰り返す

l.87 cntを初期化

l.88 数値列の先頭から最後の比較位置まで以下を繰り返す

l.89 左の値の方が大きければ、左右の値を入れ替えて、cntに1を加算

--クイックソート--

l.104 leftの値よりrightの値が大きければ以下を実行

l.105 int型のi,j,pivot,City型のtmpを定義

l.110 無条件に繰り返し

l.111 左から順番にpivotより大きい値を探し、見つかった場所をiとする

l.114 右から順番にpivotより小さい値を探し、見つかった場所をjとする

l.117 もしiがj以上ならば、l.110のwhile文を抜ける

l.120 iがjより小さければiとjの値を入れ替えてl.111に戻る

l.127 pivotの値とjの値を入れ替える

l.131 再起呼び出しで左側と右側をQuickSortする
```

## 修正履歴

