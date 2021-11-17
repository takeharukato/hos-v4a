# カーネル ドキュメント


## 概要

本ドキュメントは Hyper Operating System V4 Advance (以下 HOS-V4a)の
カーネルについての説明を記載します。

## 準備するもの

カーネルのビルドには、ターゲットCPU用のコンパイラの他に以下の何れかの
環境が必要になります。

* GNU Make環境:  GNU Make + GNU Compiler Collection (gcc) (Linux,Free-BSD, Cygwin などの環境)
* nmake環境:    nmake + cl (Windows + Visual-C++ 環境)


何れかの環境をホスト側に事前に準備し、`PATH`などの環境変数を準備して、
コンパイラやmakeが動く状態にしておいてください。

## カーネルのビルド

`kernel/build` ディレクトリの下に、各ターゲットプロセッサ毎にビルド環境を用意しています。

`kernel/build` 以下のディレクトリは

```
プロセッサアーキテクチャ名/バージョン名/コンパイラセット
```

の順で、階層管理されています。

例えば、SH2 を日立製のshcコンパイラで使いたい場合は

```
kernel/build/sh/sh2/shc
```

がビルドディレクトリとなります。

ビルドディレクトリにおいて

* GNU make の場合: `make`
* nmake の場合: `nmake`

など、と実行すれば、カーネルライブラリが出来上がります。
