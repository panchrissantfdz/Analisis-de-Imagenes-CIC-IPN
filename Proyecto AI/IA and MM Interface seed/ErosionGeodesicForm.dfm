object FormErosionGeodesic: TFormErosionGeodesic
  Left = 662
  Top = 112
  BorderStyle = bsToolWindow
  Caption = 'Geodesic erosion'
  ClientHeight = 206
  ClientWidth = 275
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnClose = FormClose
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
  object ImageMarker: TImage
    Left = 16
    Top = 16
    Width = 105
    Height = 105
    Stretch = True
  end
  object ImageMask: TImage
    Left = 152
    Top = 16
    Width = 105
    Height = 105
    Stretch = True
  end
  object BitBtnMarker: TBitBtn
    Left = 32
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Mask'
    TabOrder = 0
    OnClick = BitBtnMarkerClick
  end
  object BitBtnMask: TBitBtn
    Left = 168
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Marker'
    TabOrder = 1
    OnClick = BitBtnMaskClick
  end
  object BitBtnOK: TBitBtn
    Left = 96
    Top = 176
    Width = 75
    Height = 25
    TabOrder = 2
    OnClick = BitBtnOKClick
    Kind = bkOK
  end
end
