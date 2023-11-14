object OperacionesLog: TOperacionesLog
  Left = 704
  Top = 117
  BorderStyle = bsToolWindow
  Caption = 'Logical Operations'
  ClientHeight = 294
  ClientWidth = 274
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel2: TBevel
    Left = 144
    Top = 8
    Width = 121
    Height = 121
  end
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 121
    Height = 121
  end
  object Image1: TImage
    Left = 16
    Top = 16
    Width = 105
    Height = 105
    Stretch = True
  end
  object Image2: TImage
    Left = 152
    Top = 16
    Width = 105
    Height = 105
    Stretch = True
  end
  object GroupBox3: TGroupBox
    Left = 176
    Top = 168
    Width = 89
    Height = 121
    TabOrder = 11
    object RadioButtonImageNot1: TRadioButton
      Left = 8
      Top = 24
      Width = 65
      Height = 17
      Caption = 'Image 1'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButtonImageNot2: TRadioButton
      Left = 8
      Top = 48
      Width = 65
      Height = 17
      Caption = 'Image 2'
      TabOrder = 1
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 232
    Width = 153
    Height = 57
    TabOrder = 4
  end
  object AND: TButton
    Left = 16
    Top = 251
    Width = 41
    Height = 25
    Caption = 'AND'
    TabOrder = 0
    OnClick = ANDClick
  end
  object OR: TButton
    Left = 64
    Top = 251
    Width = 41
    Height = 25
    Caption = 'OR'
    TabOrder = 1
    OnClick = ORClick
  end
  object XOR: TButton
    Left = 112
    Top = 251
    Width = 41
    Height = 25
    Caption = 'XOR'
    TabOrder = 2
    OnClick = XORClick
  end
  object NOT: TButton
    Left = 184
    Top = 251
    Width = 73
    Height = 25
    Caption = 'NOT'
    TabOrder = 3
    OnClick = NOTClick
  end
  object BitBtnI1: TBitBtn
    Left = 32
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Image 1'
    TabOrder = 5
    OnClick = BitBtnI1Click
  end
  object BitBtnI2: TBitBtn
    Left = 168
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Image 2'
    TabOrder = 6
    OnClick = BitBtnI2Click
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 168
    Width = 161
    Height = 65
    TabOrder = 7
  end
  object CheckBoxFitSizeImage: TCheckBox
    Left = 16
    Top = 184
    Width = 145
    Height = 17
    Caption = 'Fit to the size of the image'
    TabOrder = 8
    OnClick = CheckBoxFitSizeImageClick
  end
  object RadioButtonImage1: TRadioButton
    Left = 24
    Top = 208
    Width = 65
    Height = 17
    Caption = 'Image 1'
    Checked = True
    Enabled = False
    TabOrder = 9
    TabStop = True
  end
  object RadioButtonImage2: TRadioButton
    Left = 96
    Top = 208
    Width = 65
    Height = 17
    Caption = 'Image 2'
    Enabled = False
    TabOrder = 10
  end
end
