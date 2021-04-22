# NK65カスタマイズ

## ビルド方法

1. <https://github.com/qmk/qmk_firmware>をcloneする
2. `keyboards/nk65/keymaps/`に<https://github.com/mimimi5/qmk-keymap-nk65>をサブモジュールとして追加する

   ```sh
   cd qmk_firmware/keyboards/nk65/keymaps
   git submodule add https://github.com/mimimi5/qmk-keymap-nk65.git mimimi5
   ```

3. コンパイルする

   ```sh
   cd ../../..
   qmk compile -kb nk65 -km mimimi5
   ```

## レイアウト

### ベースレイヤー (#0)

Windows用のレイヤーです。

### Macレイヤー (#1)

ベースレイヤーに一部Mac用のキーアサインをオーバーレイするレイヤーです。

### Fnレイヤー (#2)

デフォルトのままです。

## インジケーター

上から順に下記レイヤーがアクティブな場合に点灯します。

1. Fnレイヤー
2. Vimレイヤー
3. Macレイヤー
