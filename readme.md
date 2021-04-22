# NK65カスタマイズ

## ビルド方法

```sh
qmk setup
cd qmk_firmware/keyboards/nk65/keymaps
git submodule add https://github.com/mimimi5/qmk-keymap-nk65.git mimimi5
qmk compile -kb nk65 -km mimimi5
```

## レイアウト

### ベースレイヤー (#0)

Windows用のレイヤーです。

### Macレイヤー (#1)

ベースレイヤーに一部Mac用のキーアサインをオーバーレイするレイヤーです。

### Fnレイヤー (#2)

デフォルトのままです。
