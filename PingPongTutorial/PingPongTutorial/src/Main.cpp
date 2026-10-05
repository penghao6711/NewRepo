#include <Windows.h>
#include <easyx.h>  

namespace {
void drawCircle(int x, int y, int radius)
{
    setlinestyle(PS_SOLID | PS_JOIN_BEVEL, 6);
    setlinecolor(YELLOW);  // 设置画笔颜色为黄色
    circle(x, y, radius);  // 以指定中心和半径绘制一个圆
}
void drawText(int x, int y, const char* text)
{
    settextcolor(RED);  // 设置文本颜色为红色
    settextstyle(60, 0, "微软雅黑");  // 设置文本样式，字体大小为60，字体为微软雅黑
    outtextxy(x, y, text);  // 在指定位置绘制文本
}
void drawCenterText(int rx, int ry, int rw, int rh)
{
    // 仅保留灰色矩形，移除文本和相关背景设置
    setfillcolor(RGB(128, 128, 128));  // 设置填充颜色为灰色
    fillrectangle(rx, ry, rx + rw, ry + rh);  // 绘制矩形，左上角为(rx, ry)，右下角为(rx + rw, ry + rh)
	drawText(rx + rw/2 - 60, ry + rh/2 - 30, "Hello");  // 在矩形内绘制文本)
}
} // namespace

int APIENTRY WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    initgraph(640, 480);    // 创建绘图窗口，大小为 640x480 像素
	//setbkcolor(RGB(128, 128, 128));  // 设置背景颜色为绿色
    cleardevice();          // 清屏，使用背景颜色填充整个窗口
    drawCircle(200, 200, 100);  // 画圆，圆心(200, 200)，半径 100
    drawText(220, 120, "你好, EasyX!");  // 绘制文本
	drawCenterText(200, 300, 200, 100);  // 绘制矩形，矩形左上角(200, 300)，宽200，高100

    // _getch();            // 窗口程序无法使用控制台输入输出
    Sleep(5000);            // 延时 5000 毫秒（声明在 Windows.h 中）

    closegraph();           // 关闭绘图窗口
    return 0;
}
