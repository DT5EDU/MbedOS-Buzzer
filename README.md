# MbedOS-Buzzer
基于Mbed OS的无源蜂鸣器库
## 声明
请勿直接抄袭代码或用作其他用途，仅适合MS Project项目使用。 请确保你使用的是无源蜂鸣器，接线方法自行查阅。  
**遇到问题先自行搜索，如果无法解决请在issue中详细描述你的问题，我们会及时回复，同时这也会方便遇到同样问题的人。**  
## 使用方法
将`Buzzer.h`和`Buzzer.cpp`文件添加到你的项目中，然后将两个文件中的`empty_template`改成你喜欢的名字，在预留的位置按照给出的示例音乐的形式编写你自己的音乐，并且修改速度。以下是一个示例：
```
buzzer & buzzer::how_to_use(void) {
    std::vector<pair<Tune,float>> music = {
        {Tune::C4,1}, {Tune::D4,1}, {Tune::E4,1}
    };
    PlayMusic(music, 90); // Remember to change the speed of the music
    return *this;
}
```
