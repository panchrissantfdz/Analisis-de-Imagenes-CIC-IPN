object FSEB: TFSEB
  Left = 535
  Top = 126
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Structure Element'
  ClientHeight = 533
  ClientWidth = 436
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClick = FormClickAction
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Imagec: TImage
    Left = 328
    Top = 400
    Width = 88
    Height = 76
    Cursor = crCross
    Hint = 'Real Size'
    ParentShowHint = False
    ShowHint = True
    OnMouseMove = ImagecMouseMove
  end
  object ImageB: TImage
    Left = 11
    Top = 8
    Width = 300
    Height = 300
    DragCursor = crHandPoint
    OnMouseMove = ImageBMouseMove
    OnMouseUp = ImageBMouseUp
  end
  object Label2: TLabel
    Left = 89
    Top = 332
    Width = 13
    Height = 15
    Caption = 'X:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 116
    Top = 332
    Width = 13
    Height = 15
    Caption = 'Y:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentFont = False
  end
  object lblcx: TLabel
    Left = 101
    Top = 332
    Width = 14
    Height = 15
    Caption = '00'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentFont = False
  end
  object lblcy: TLabel
    Left = 128
    Top = 332
    Width = 14
    Height = 15
    Caption = '00'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentFont = False
  end
  object lblSizeEE: TLabel
    Left = 18
    Top = 370
    Width = 42
    Height = 13
    Caption = 'Grid Size'
  end
  object lblx: TLabel
    Left = 91
    Top = 372
    Width = 7
    Height = 13
    Caption = 'X'
  end
  object lbly: TLabel
    Left = 150
    Top = 372
    Width = 7
    Height = 13
    Caption = 'Y'
  end
  object lblAncho: TLabel
    Left = 24
    Top = 371
    Width = 28
    Height = 13
    Caption = 'Width'
    Visible = False
  end
  object lblAlto: TLabel
    Left = 23
    Top = 409
    Width = 31
    Height = 13
    Caption = 'Height'
    Visible = False
  end
  object lblGrosor: TLabel
    Left = 189
    Top = 413
    Width = 49
    Height = 13
    Caption = 'Thickness'
    Visible = False
  end
  object SBLoad: TSpeedButton
    Left = 256
    Top = 396
    Width = 24
    Height = 25
    Hint = 'Load SE'
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
      5555555555555555555555555555555555555555555555555555555555555555
      555555555555555555555555555555555555555FFFFFFFFFF555550000000000
      55555577777777775F55500B8B8B8B8B05555775F555555575F550F0B8B8B8B8
      B05557F75F555555575F50BF0B8B8B8B8B0557F575FFFFFFFF7F50FBF0000000
      000557F557777777777550BFBFBFBFB0555557F555555557F55550FBFBFBFBF0
      555557F555555FF7555550BFBFBF00055555575F555577755555550BFBF05555
      55555575FFF75555555555700007555555555557777555555555555555555555
      5555555555555555555555555555555555555555555555555555}
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    OnClick = SBLoadClick
  end
  object SBSave: TSpeedButton
    Left = 273
    Top = 428
    Width = 24
    Height = 25
    Hint = 'Save SE'
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333FFFFFFFFFFFFF33000077777770033377777777777773F000007888888
      00037F3337F3FF37F37F00000780088800037F3337F77F37F37F000007800888
      00037F3337F77FF7F37F00000788888800037F3337777777337F000000000000
      00037F3FFFFFFFFFFF7F00000000000000037F77777777777F7F000FFFFFFFFF
      00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
      00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
      00037F7F333333337F7F000FFFFFFFFF07037F7F33333333777F000FFFFFFFFF
      0003737FFFFFFFFF7F7330099999999900333777777777777733}
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    OnClick = SBSaveClick
  end
  object Label1: TLabel
    Left = 538
    Top = 280
    Width = 36
    Height = 15
    Caption = 'Level:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentFont = False
  end
  object lblevel: TLabel
    Left = 576
    Top = 281
    Width = 18
    Height = 13
    Caption = '000'
  end
  object ImgLevel: TImage
    Left = 447
    Top = 298
    Width = 239
    Height = 15
    Visible = False
  end
  object LblRote: TLabel
    Left = 193
    Top = 371
    Width = 40
    Height = 13
    Caption = 'Rotation'
  end
  object LblStart: TLabel
    Left = 82
    Top = 413
    Width = 22
    Height = 13
    Caption = 'Start'
    Visible = False
  end
  object LblEnd: TLabel
    Left = 142
    Top = 413
    Width = 19
    Height = 13
    Caption = 'End'
    Visible = False
  end
  object ImgNLevel: TImage
    Left = 447
    Top = 314
    Width = 239
    Height = 15
    Transparent = True
    Visible = False
  end
  object Label4: TLabel
    Left = 83
    Top = 312
    Width = 65
    Height = 15
    Caption = 'Cell coord.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial Black'
    Font.Style = []
    ParentFont = False
  end
  object lblvertice: TLabel
    Left = 16
    Top = 412
    Width = 47
    Height = 13
    Caption = 'Num. Vert'
    Visible = False
  end
  object Bevel1: TBevel
    Left = 10
    Top = 368
    Width = 238
    Height = 105
  end
  object SBCreate: TSpeedButton
    Left = 256
    Top = 364
    Width = 24
    Height = 25
    Hint = 'Create SE'
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000000
      000033333377777777773333330FFFFFFFF03FF3FF7FF33F3FF700300000FF11
      FFF077F777773F737737E00BFBFB0FFFF1F07773333F7F3333F7E0BFBF000FFF
      111077F3337773F3F737E0FBFBFBF0F001F077F3333FF7F77F37E0BFBF00000B
      0FF077F3337777737337E0FBFBFBFBF0FFF077F33FFFFFF73337E0BF0000000F
      FFF077FF777777733FF7000BFB00B0FF11107773FF77373377373330000B0FFF
      FFF03337777373333FF7333330B0FFFF00003333373733FF777733330B0FF11F
      0FF03333737F37737F373330B00FF11F0F033337F77F33337F733309030FFFFF
      00333377737FFFFF773333303300000003333337337777777333}
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    OnClick = SBCreateClick
  end
  object SBClean: TSpeedButton
    Left = 283
    Top = 364
    Width = 24
    Height = 25
    Hint = 'Erase SE'
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
      555557777F777555F55555555005550555557777777755F75555555550055555
      555577F5777F57555555555550050555555577FF577F5FF55555550000050055
      5555577FF77577FF555555000050110555555577F757777FF555555550099910
      555555FF75777777FF555555500999910555577F5F77777775F5555550009990
      3055577F75F77777575F55555555090B030555775755777575755555555550B0
      B03055555F555757575755550555550B0B335555755555757555555555555550
      BBB35555F55555575F555550555555550BBB55575555555575F5555555555555
      50BB555555555555575F555555555555550B5555555555555575}
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    OnClick = SBCleanClick
  end
  object SBFDG: TSpeedButton
    Left = 283
    Top = 396
    Width = 24
    Height = 25
    Hint = 'Geo.Dist.Func.'
    Glyph.Data = {
      36050000424D3605000000000000360400002800000010000000100000000100
      0800000000000001000000000000000000000001000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
      A6000020400000206000002080000020A0000020C0000020E000004000000040
      20000040400000406000004080000040A0000040C0000040E000006000000060
      20000060400000606000006080000060A0000060C0000060E000008000000080
      20000080400000806000008080000080A0000080C0000080E00000A0000000A0
      200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
      200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
      200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
      20004000400040006000400080004000A0004000C0004000E000402000004020
      20004020400040206000402080004020A0004020C0004020E000404000004040
      20004040400040406000404080004040A0004040C0004040E000406000004060
      20004060400040606000406080004060A0004060C0004060E000408000004080
      20004080400040806000408080004080A0004080C0004080E00040A0000040A0
      200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
      200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
      200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
      20008000400080006000800080008000A0008000C0008000E000802000008020
      20008020400080206000802080008020A0008020C0008020E000804000008040
      20008040400080406000804080008040A0008040C0008040E000806000008060
      20008060400080606000806080008060A0008060C0008060E000808000008080
      20008080400080806000808080008080A0008080C0008080E00080A0000080A0
      200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
      200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
      200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
      2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
      2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
      2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
      2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
      2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
      2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
      2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
      FFFFFCFCFCFCFCFCFCFCFFFFFFFFFFFFFFFFFC000000000000FCFFFFFFFFFFFF
      FFFFFC00A4A4A4A400FCFFFFFFFFFFFFFFFFFC00A40707A400FCFFFFFFFFFFFF
      FFFFFC00A40707A400FCFFFFFFFFFFFFFFFFFC00A40707A400FCFFFFFFFFFFFF
      FFFFFC00A4A4A4A400FCFCFCFCFCFCFCFCFCFC000000000000FCFC00A4F70707
      FFFCFCFCFCFCFCFCFCFCFC00A4F70707FFFCFFFFFFFFFFFFFFFFFC00A4F70707
      07FCFFFFFFFFFFFFFFFFFC00A4F7070707FCFFFFFFFFFFFFFFFFFC00A4F7F7F7
      F7FCFFFFFFFFFFFFFFFFFC00A4A4A4A4A4FCFFFFFFFFFFFFFFFFFC0000000000
      00FCFFFFFFFFFFFFFFFFFCFCFCFCFCFCFCFCFFFFFFFFFFFFFFFF}
    ParentShowHint = False
    ShowHint = True
    OnClick = SBFDGClick
  end
  object Label8: TLabel
    Left = 96
    Top = 456
    Width = 56
    Height = 13
    Caption = '(In degrees)'
    Visible = False
  end
  object LabelForeground: TLabel
    Left = 320
    Top = 356
    Width = 105
    Height = 13
    Caption = 'Foreground: Black'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object LabelBackground: TLabel
    Left = 320
    Top = 376
    Width = 106
    Height = 13
    Caption = 'Background: Aqua'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object GroupBox2: TGroupBox
    Left = 328
    Top = 32
    Width = 89
    Height = 73
    TabOrder = 32
    object Cuadro: TRadioButton
      Left = 7
      Top = 14
      Width = 58
      Height = 17
      Caption = 'Square'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = CuadroClick
    end
    object Rectangulo: TRadioButton
      Left = 7
      Top = 32
      Width = 67
      Height = 17
      Caption = 'Rectangle'
      TabOrder = 1
      OnClick = RectanguloClick
    end
    object Circulo: TRadioButton
      Left = 7
      Top = 50
      Width = 58
      Height = 17
      Caption = 'Circle'
      TabOrder = 2
      OnClick = CirculoClick
    end
  end
  object RadioGroupCustomize: TRadioGroup
    Left = 328
    Top = 316
    Width = 105
    Height = 33
    Items.Strings = (
      'Customize')
    TabOrder = 31
    Visible = False
    OnClick = RadioGroupCustomizeClick
  end
  object RadioGroupInsolatedpoints: TRadioGroup
    Left = 328
    Top = 184
    Width = 105
    Height = 49
    Caption = 'Insolated points'
    Items.Strings = (
      '4-connected'
      '8-connected')
    TabOrder = 30
    Visible = False
    OnClick = RadioGroupInsolatedpointsClick
  end
  object RadioGroupPruning: TRadioGroup
    Left = 328
    Top = 120
    Width = 105
    Height = 65
    Caption = 'Pruning'
    Items.Strings = (
      '4-connected'
      '8-connected A'
      '8-connected B')
    TabOrder = 29
    Visible = False
    OnClick = RadioGroupPruningClick
  end
  object RadioGroupSkeletons: TRadioGroup
    Left = 328
    Top = 32
    Width = 105
    Height = 89
    Caption = 'Skeletons'
    ItemIndex = 0
    Items.Strings = (
      '4-connected A'
      '4-connected B'
      '8-connected A'
      '8-connected B')
    TabOrder = 28
    Visible = False
    OnClick = RadioGroupSkeletonsClick
  end
  object ChbLevel: TCheckBox
    Left = 333
    Top = 375
    Width = 73
    Height = 17
    Caption = 'GrayLevel'
    Enabled = False
    TabOrder = 2
    Visible = False
  end
  object chkInv: TCheckBox
    Left = 447
    Top = 343
    Width = 50
    Height = 17
    Caption = 'Revert'
    TabOrder = 0
  end
  object cmdCleanL: TButton
    Left = 613
    Top = 341
    Width = 75
    Height = 25
    Caption = 'Clean Levels'
    TabOrder = 1
    Visible = False
  end
  object Tamval: TEdit
    Left = 17
    Top = 385
    Width = 34
    Height = 21
    TabOrder = 3
    Text = '3'
    OnChange = TamvalChange
  end
  object UpDownT: TUpDown
    Left = 51
    Top = 385
    Width = 15
    Height = 21
    Associate = Tamval
    Min = 1
    Max = 99
    Position = 3
    TabOrder = 4
    Wrap = False
    OnClick = UpDownTClick
  end
  object EditX: TEdit
    Left = 74
    Top = 385
    Width = 34
    Height = 21
    TabOrder = 5
    Text = '1'
    OnChange = EditXChange
  end
  object UpDownX: TUpDown
    Left = 108
    Top = 385
    Width = 15
    Height = 21
    Associate = EditX
    Min = 0
    Max = 99
    Position = 1
    TabOrder = 6
    Wrap = False
    OnClick = UpDownXClick
  end
  object EditY: TEdit
    Left = 133
    Top = 385
    Width = 34
    Height = 21
    TabOrder = 7
    Text = '1'
    OnChange = EditYChange
  end
  object UpDownY: TUpDown
    Left = 167
    Top = 385
    Width = 15
    Height = 21
    Associate = EditY
    Min = 0
    Max = 99
    Position = 1
    TabOrder = 8
    Wrap = False
    OnClick = UpDownYClick
  end
  object EditW: TEdit
    Left = 17
    Top = 385
    Width = 34
    Height = 21
    TabOrder = 9
    Text = '5'
    Visible = False
    OnChange = EditWChange
  end
  object UpDownW: TUpDown
    Left = 51
    Top = 385
    Width = 15
    Height = 21
    Associate = EditW
    Min = 1
    Max = 99
    Position = 5
    TabOrder = 10
    Visible = False
    Wrap = False
    OnClick = UpDownWClick
  end
  object EditH: TEdit
    Left = 17
    Top = 426
    Width = 34
    Height = 21
    TabOrder = 11
    Text = '2'
    Visible = False
    OnChange = EditHChange
  end
  object UpDownH: TUpDown
    Left = 51
    Top = 426
    Width = 15
    Height = 21
    Associate = EditH
    Min = 1
    Max = 99
    Position = 2
    TabOrder = 12
    Visible = False
    Wrap = False
    OnClick = UpDownHClick
  end
  object EditG: TEdit
    Left = 190
    Top = 427
    Width = 34
    Height = 21
    TabOrder = 13
    Text = '1'
    Visible = False
    OnChange = EditGChange
  end
  object UpDownG: TUpDown
    Left = 224
    Top = 427
    Width = 15
    Height = 21
    Associate = EditG
    Min = 1
    Max = 99
    Position = 1
    TabOrder = 14
    Visible = False
    Wrap = False
    OnClick = UpDownGClick
  end
  object EditVert: TEdit
    Left = 16
    Top = 426
    Width = 34
    Height = 21
    TabOrder = 15
    Text = '3'
    Visible = False
    OnChange = EditVertChange
  end
  object UpDownV: TUpDown
    Left = 50
    Top = 426
    Width = 15
    Height = 21
    Associate = EditVert
    Min = 3
    Max = 8
    Position = 3
    TabOrder = 16
    Visible = False
    Wrap = False
    OnClick = UpDownVClick
  end
  object EditS: TEdit
    Left = 73
    Top = 427
    Width = 34
    Height = 21
    TabOrder = 17
    Text = '0'
    Visible = False
    OnChange = EditSChange
  end
  object UpDownS: TUpDown
    Left = 107
    Top = 427
    Width = 15
    Height = 21
    Associate = EditS
    Min = 0
    Max = 360
    Position = 0
    TabOrder = 18
    Visible = False
    Wrap = False
    OnClick = UpDownSClick
  end
  object EditE: TEdit
    Left = 133
    Top = 427
    Width = 34
    Height = 21
    TabOrder = 19
    Text = '45'
    Visible = False
    OnChange = EditEChange
  end
  object UpDownE: TUpDown
    Left = 167
    Top = 427
    Width = 15
    Height = 21
    Associate = EditE
    Min = 0
    Max = 360
    Position = 45
    TabOrder = 20
    Visible = False
    Wrap = False
    OnClick = UpDownEClick
  end
  object EditR: TEdit
    Left = 190
    Top = 385
    Width = 34
    Height = 21
    TabOrder = 21
    Text = '0'
    OnChange = EditRChange
  end
  object UpDownR: TUpDown
    Left = 224
    Top = 385
    Width = 17
    Height = 21
    Associate = EditR
    Min = 0
    Max = 270
    Increment = 90
    Position = 0
    TabOrder = 22
    Wrap = True
    OnClick = UpDownRClick
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 480
    Width = 81
    Height = 17
    Caption = 'Red Plane'
    TabOrder = 23
  end
  object CheckBox2: TCheckBox
    Left = 104
    Top = 480
    Width = 81
    Height = 17
    Caption = 'Green Plane'
    Checked = True
    State = cbChecked
    TabOrder = 24
  end
  object CheckBox3: TCheckBox
    Left = 192
    Top = 480
    Width = 81
    Height = 17
    Caption = 'Blue Plane'
    TabOrder = 25
  end
  object BitBtnOK: TBitBtn
    Left = 336
    Top = 488
    Width = 75
    Height = 25
    TabOrder = 26
    OnClick = BitBtnOKClick
    Kind = bkOK
  end
  object CheckBoxCompositeSE: TCheckBox
    Left = 328
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Composite SE'
    TabOrder = 27
    OnClick = CheckBoxCompositeSEClick
  end
  object RadioButtonBackground: TRadioButton
    Left = 320
    Top = 376
    Width = 97
    Height = 17
    Caption = 'Background'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 33
    Visible = False
  end
  object RadioButtonForeground: TRadioButton
    Left = 320
    Top = 356
    Width = 97
    Height = 17
    Caption = 'Foreground'
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 34
    TabStop = True
    Visible = False
  end
  object RadioGroupEndpoints: TRadioGroup
    Left = 328
    Top = 232
    Width = 105
    Height = 89
    Caption = 'Endpoints'
    Items.Strings = (
      '4-connected A'
      '4-connected B'
      '4-connected C'
      '4-connected D')
    TabOrder = 35
    Visible = False
    OnClick = RadioGroupEndpointsClick
  end
  object CheckBoxAllplanes: TCheckBox
    Left = 104
    Top = 504
    Width = 97
    Height = 17
    Caption = 'All planes'
    TabOrder = 36
    OnClick = CheckBoxAllplanesClick
  end
  object CheckBoxComplement: TCheckBox
    Left = 192
    Top = 320
    Width = 97
    Height = 17
    Caption = 'Complement'
    TabOrder = 37
    OnClick = CheckBoxComplementClick
  end
  object GuardaEE: TSaveDialog
    DefaultExt = 'se'
    Filter = 'Structure Element (*.se)|*.se'
    InitialDir = 'C:\Structure Elements'
    Title = 'Save Structure Elements'
    Left = 82
    Top = 17
  end
  object Abre: TOpenDialog
    DefaultExt = 'se'
    Filter = 'Structure Element (*.se)|*.se'
    InitialDir = 'C:\Structure Elements'
    Title = 'Open Structure Elements'
    Left = 48
    Top = 17
  end
end
