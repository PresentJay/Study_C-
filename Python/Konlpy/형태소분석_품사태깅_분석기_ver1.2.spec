# -*- mode: python ; coding: utf-8 -*-

block_cipher = None


a = Analysis(['형태소분석_품사태깅_분석기_ver1.2.py'],
             pathex=['D:\\Programming Study\\Study_Languages\\Python\\Konlpy'],
             binaries=[],
             datas=[],
             hiddenimports=[],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          [],
          exclude_binaries=True,
          name='형태소분석_품사태깅_분석기_ver1.2',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          console=True )
coll = COLLECT(exe,
               a.binaries,
               a.zipfiles,
               a.datas,
               strip=False,
               upx=True,
               upx_exclude=[],
               name='형태소분석_품사태깅_분석기_ver1.2')
