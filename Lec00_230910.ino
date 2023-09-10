// Lecture 0 Fade LED
// created by StvLi, Sep 10th 2023
// share to Jiang HC, Wang HC, Kang JN, Zhang XR

int brightness = 0;   // 亮度变化范围：0~63
int stepLength = 5；  // 单次变化亮度量
int delayTime  = 100；// 更新时间100ms

int state = 0;        // 状态0：亮度递增 状态1：亮度递减
int signalPin = 3;    // 输出引脚

void setup()
{
  pinMode(signalPin, OUTPUT);
}

void loop()
{
  analogWrite(signalPin, brightness);
  
  if( brightness >= 63 && state == 0)  state = 1;
  if( brightness <= 0  && state == 1)  state = 0;
  // 小灯变亮：0 -> 63
  if(state == 0)
  {
      if( brightness < 63 )
    {
      brightness = brightness + 5;
    }
    else{
      brightness = 63;  
    }
  }  
  // 小灯变暗：255 -> 0
  if(state == 1)
  {
    if( brightness > 0 )
    {
      brightness = brightness - 5;
    }
    else{
      brightness = 0;  
    }
  }
  delay(delayTime);
}
