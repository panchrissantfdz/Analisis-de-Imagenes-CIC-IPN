object PropertiesForm: TPropertiesForm
  Left = 335
  Top = 241
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  ClientHeight = 357
  ClientWidth = 637
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
  object Propierties_page: TTabbedNotebook
    Left = 0
    Top = 0
    Width = 638
    Height = 359
    Align = alCustom
    TabFont.Charset = DEFAULT_CHARSET
    TabFont.Color = clBtnText
    TabFont.Height = -11
    TabFont.Name = 'MS Sans Serif'
    TabFont.Style = []
    TabOrder = 0
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Image'
      object ImagPro: TImage
        Left = 8
        Top = 16
        Width = 89
        Height = 89
        Proportional = True
        Stretch = True
      end
      object GroupBox1: TGroupBox
        Left = 112
        Top = 144
        Width = 513
        Height = 185
        Caption = 'Source File'
        TabOrder = 0
        object Name: TLabel
          Left = 72
          Top = 120
          Width = 28
          Height = 13
          Caption = 'Name'
        end
        object Label1: TLabel
          Left = 16
          Top = 120
          Width = 37
          Height = 13
          Caption = 'Name : '
        end
        object Label2: TLabel
          Left = 16
          Top = 48
          Width = 49
          Height = 13
          Caption = 'File Type :'
        end
        object Type: TLabel
          Left = 72
          Top = 48
          Width = 24
          Height = 13
          Caption = 'Type'
        end
        object Label6: TLabel
          Left = 16
          Top = 64
          Width = 28
          Height = 13
          Caption = 'Path: '
        end
        object path: TLabel
          Left = 72
          Top = 64
          Width = 425
          Height = 49
          AutoSize = False
          Caption = 'Path'
          Constraints.MaxHeight = 49
          Constraints.MaxWidth = 425
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object Size: TLabel
          Left = 16
          Top = 16
          Width = 23
          Height = 13
          Caption = 'Size:'
        end
        object LabelSize: TLabel
          Left = 72
          Top = 16
          Width = 20
          Height = 13
          Caption = 'Size'
        end
        object Extension: TLabel
          Left = 16
          Top = 32
          Width = 49
          Height = 13
          Caption = 'Extension:'
        end
        object LabelExtension: TLabel
          Left = 72
          Top = 32
          Width = 46
          Height = 13
          Caption = 'Extension'
        end
      end
      object GroupBox2: TGroupBox
        Left = 112
        Top = 8
        Width = 513
        Height = 129
        Caption = 'Image'
        TabOrder = 1
        object PixelesPerInches: TLabel
          Left = 104
          Top = 68
          Width = 70
          Height = 13
          Caption = 'Pixels Per Inch'
          Visible = False
        end
        object LPixels: TLabel
          Left = 16
          Top = 68
          Width = 73
          Height = 13
          Caption = 'Pixels Per Inch:'
          Visible = False
        end
        object Label3: TLabel
          Left = 16
          Top = 16
          Width = 57
          Height = 13
          Caption = 'Dimensions:'
        end
        object dimpix: TLabel
          Left = 104
          Top = 16
          Width = 29
          Height = 13
          Caption = 'dimpix'
        end
        object dimin: TLabel
          Left = 104
          Top = 32
          Width = 24
          Height = 13
          Caption = 'dimin'
        end
        object Label4: TLabel
          Left = 16
          Top = 88
          Width = 57
          Height = 13
          Caption = 'Pixel Depth:'
        end
        object PixelDepth: TLabel
          Left = 104
          Top = 88
          Width = 54
          Height = 13
          Caption = 'Pixel Depth'
        end
        object Label7: TLabel
          Left = 16
          Top = 104
          Width = 57
          Height = 13
          Caption = 'Pixel Colors:'
        end
        object PixelColors: TLabel
          Left = 104
          Top = 104
          Width = 54
          Height = 13
          Caption = 'Pixel Colors'
        end
        object dimcm: TLabel
          Left = 104
          Top = 48
          Width = 30
          Height = 13
          Caption = 'dimcm'
        end
      end
    end
    object TTabPage
      Left = 4
      Top = 24
      Caption = 'Applied Functions'
      DesignSize = (
        630
        331)
      object NameSyst: TLabel
        Left = 8
        Top = 120
        Width = 82
        Height = 13
        Caption = 'List Of Functions:'
      end
      object Image1: TImage
        Left = 8
        Top = 16
        Width = 89
        Height = 89
        Proportional = True
        Stretch = True
      end
      object LabelListOfFunctions: TLabel
        Left = 8
        Top = 152
        Width = 515
        Height = 132
        Anchors = [akLeft, akTop, akRight, akBottom]
        AutoSize = False
        Caption = 'List Of Functions'
        Constraints.MaxHeight = 200
        Constraints.MaxWidth = 600
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        WordWrap = True
      end
    end
  end
end
