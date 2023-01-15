# atcoder-devcontainer

[AtCoder](https://atcoder.jp/) C++向けの開発環境を
[Dev Container](https://code.visualstudio.com/docs/devcontainers/containers)
にまとめました。

以下のソフトがインストールされています。

- g++ (with [ac_library](https://github.com/atcoder/ac-library))
- [online-judge-tools](https://github.com/online-judge-tools/oj)
- [atcoder-cli](https://github.com/Tatamo/atcoder-cli)

`check` コマンドでソースコードのビルドとサンプルケースのテストを実行できます。

## 使い方

このリポジトリをクローンし、フォルダ名を `.devcontainer` にします。

`git clone <URL>`

`mv atcoder-devcontainer .devcontainer`

VSCodeから Dev Container で開くと、セットアップが始まります。

ツールの使い方は、それぞれのREADMEをご参照ください。
