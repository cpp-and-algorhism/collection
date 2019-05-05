# collection

## boost ライブラリのインストール for mac

````
brew install boost

brew info boost
//ver 1.69.0 2019-04-07
````

## 開発環境の用意

### extension インストール
extensionをインストールする。

````
code --install-extension ms-vscode.cpptools
code --install-extension xaver.clang-format
code --install-extension twxs.cmake
code --install-extension vector-of-bool.cmake-tools
code --install-extension maddouri.cmake-tools-helper
code --install-extension donjayamanne.githistory
````


### extension セッティング

#### clang-format
Editor: Format On Save を有効に。

#### tasks.json

Command + Shift + p で、"tasks"と入力し、"Configure Tasks"を選ぶ。
"clang++ build archive file" を選ぶと、tasks.jsonが作成される。


#### c_cpp_property.json

Command + Shift + p で、"Edit config"と入力し、"C/C++ Edit configurations"を選ぶ。
.vscode を選ぶと、c_cpp_properties.jsonが作成される。

ファイルの中の次の部分をclang に書き換える。

    "compilerPath": "/usr/bin/clang++",

#### cmake の設定

Command + Shift + p で、"CMake"と入力し、"CMake Build"を選ぶ。

そしてCLANGを選ぶ。

## ビルド

F7 keyでビルドができる。


