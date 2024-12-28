# -*- mode: python ; coding: utf-8 -*-


a = Analysis(
    ['tkmain.py'],
    pathex=[],
    binaries=[],
    datas=[('logo.png', 'images'), ('icon1.png', 'images'), ('icon2.png', 'images'), ('icon3.png', 'images')],
    hiddenimports=['tkinter', 'pillow'],
    hookspath=[],
    hooksconfig={},
    runtime_hooks=[],
    excludes=[],
    noarchive=False,
    optimize=0,
)
pyz = PYZ(a.pure)

exe = EXE(
    pyz,
    a.scripts,
    a.binaries,
    a.datas,
    [],
    name='537Toolbox.app',
    debug=False,
    bootloader_ignore_signals=False,
    strip=False,
    upx=True,
    upx_exclude=[],
    runtime_tmpdir=None,
    console=False,
    disable_windowed_traceback=False,
    argv_emulation=False,
    target_arch=None,
    codesign_identity=None,
    entitlements_file=None,
)
