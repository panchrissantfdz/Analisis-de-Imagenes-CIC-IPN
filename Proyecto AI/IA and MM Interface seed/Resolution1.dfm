object FrmRes1: TFrmRes1
  Left = 563
  Top = 131
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'Level Resolution'
  ClientHeight = 210
  ClientWidth = 208
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 80
    Top = 8
    Width = 121
    Height = 57
    Caption = 'Continuous'
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 88
    Top = 32
    Width = 89
    Height = 21
    TabOrder = 0
    Text = '2'
    OnChange = Edit1Change
  end
  object BitBtnOK: TBitBtn
    Left = 64
    Top = 176
    Width = 75
    Height = 25
    TabOrder = 1
    OnClick = BitBtnOKClick
    Kind = bkOK
  end
  object UpDown1: TUpDown
    Left = 177
    Top = 32
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 0
    Max = 257
    Position = 2
    TabOrder = 2
    Wrap = False
    OnClick = UpDown1Click
  end
  object RadioGroup1: TRadioGroup
    Left = 8
    Top = 8
    Width = 65
    Height = 161
    Caption = 'Discreet'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemIndex = 0
    Items.Strings = (
      '2'
      '4'
      '8'
      '16'
      '32'
      '64'
      '128'
      '256')
    ParentFont = False
    TabOrder = 3
    OnClick = RadioGroup1Click
  end
  object GroupBox2: TGroupBox
    Left = 88
    Top = 72
    Width = 105
    Height = 97
    Caption = 'Grayscale'
    TabOrder = 5
    object RadioButtonA: TRadioButton
      Left = 16
      Top = 16
      Width = 73
      Height = 17
      Caption = 'Averaged'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = RadioButtonAClick
    end
    object RadioButtonW: TRadioButton
      Left = 16
      Top = 32
      Width = 73
      Height = 17
      Caption = 'Weighted'
      TabOrder = 1
      OnClick = RadioButtonWClick
    end
    object RadioButtonRGBG: TRadioButton
      Left = 16
      Top = 48
      Width = 73
      Height = 17
      Caption = 'RGB Gray'
      TabOrder = 2
      OnClick = RadioButtonRGBGClick
    end
    object CheckBoxR: TCheckBox
      Left = 8
      Top = 72
      Width = 33
      Height = 17
      Caption = 'R'
      TabOrder = 3
    end
    object CheckBoxG: TCheckBox
      Left = 40
      Top = 72
      Width = 33
      Height = 17
      Caption = 'G'
      Checked = True
      State = cbChecked
      TabOrder = 4
    end
    object CheckBoxB: TCheckBox
      Left = 72
      Top = 72
      Width = 25
      Height = 17
      Caption = 'B'
      TabOrder = 5
    end
  end
end
