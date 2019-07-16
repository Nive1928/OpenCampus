オープンキャンパス2019年度用リポジトリ
========

    $ 懇切丁寧なREADME

このリポジトリに皆さんの作品をpushしてください。

そのために、このリポジトリをforkしてbranch切ってclone作って自分の手元で編集してaddしてcommitしてpushしてプルリク送ってください。
(多分こうなはず)

なお、タスク管理をして、各員の更新漏れがないようにしくつもり。

## みなさんがやること
1. 自分のリポジトリをpushする
2. プルリクを送る
3. [進捗確認用プロジェクト](https://github.com/KNCT-KPC/OpenCampus/projects/1)から自分のタスクだと思えるものを適当な状態に遷移させる

---

## 各自のリポジトリに必要なもの

    whose_repository     # 誰のリポジトリかわかる名前(アルファベット記法)
    ├─ src               # ソースファイルを置くリポジトリ
    │   └─ program.hoge  # ソースファイル
    │   
    └─ README.txt        # りーどみー(.mdでもなんでもいいよ)

必ずしもこうしろというわけではないが、なるべく踏襲してほしい。

---

## 開発方法(暫定)

### 初回だけ

    $ git clone https://github.com/KNCT-KPC/OpenCampus.git

### その他

    $ cd OpenCampus/2019/"Your Repository"/
    $ git pull
    $ vim program.hoge
    $ git add -A
    $ git commit -m "変更内容"
    $ git push origin master

---

## READMEについて

各ディレクトリ事に以下の内容を含めたREADMEを置いてください。
- プロジェクトメンバー
- プログラムの解説
- 作動方法

また、以下の内容をREADMEに書くか、他のテキストファイルに書いて置くとモテます。
- 更新履歴

更に、以下の内容を認めたテキストファイルを用意しておくと後輩系彼女(てきとう)が爆誕します。
- 各ファイルの説明
- 関数（メソッド）単位での詳細なプログラムの解説

