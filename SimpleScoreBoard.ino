#include <stdio.h>
#include <LiquidCrystal.h>

//  液晶のインスタンス
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

boolean button0;
boolean button1;
boolean button2;

//  左チームの得点
int score_left;

//  右チームの得点
int score_right;

//  初期設定を行う
void setup()
{
  //  液晶の処理を開始する
  lcd.begin(16, 2);
}

//  ボタンの状態を更新する
void updateButtonState()
{
  button0 = (analogRead(0) > 1020) ? true : false;
  button1 = (analogRead(1) > 1020) ? true : false;
  button2 = (analogRead(2) > 1020) ? true : false;
}

void loop()
{
  lcd.clear();
  updateButtonState();

  if (button2)
    score_left++;

  if (button0)
    score_right++;

  if (button1)
  {
    score_left = 0;
    score_right = 0;
  }

  char left[3];
  sprintf(left, "%d", score_left);

  char right[3];
  sprintf(right, "%2d", score_right);
  
  lcd.setCursor(0, 0);
  lcd.print("SimpleScoreBoard");

  lcd.setCursor(1, 1);
  lcd.print(left);

  lcd.setCursor(7, 1);
  lcd.print("--");

  lcd.setCursor(13, 1);
  lcd.print(right);

  delay(200);
}
