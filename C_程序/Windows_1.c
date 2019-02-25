#pragma comment(linker,"/SUBSYSTEM:Windows  /ENTRY:mainCRTStartup")
#include <windows.h>
/* 使类名成为全局变量 */
TCHAR szClassName[ ] = TEXT("WindowsApp");
/* 这个函数由Windows内部函数DispatchMessage()调用 */
LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc ;
    PAINTSTRUCT ps ;
    RECT rect ;
    switch (message)  /* 处理信息 */
    {
        case WM_DESTROY:
            PostQuitMessage (0);  /* 发送WM_QUIT到消息队列 */
            break;
        case WM_PAINT:
            hdc = BeginPaint (hWnd, &ps) ;
            GetClientRect (hWnd, &rect) ;
            DrawText (hdc, TEXT("Hello, Windows NT!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER) ;
            EndPaint (hWnd, &ps) ;
            break ;
        default:  /* 不处理的消息 */
            return DefWindowProc (hWnd, message, wParam, lParam);
    }
    return 0;
}
/* 下面是主函数 */
int main ( void )
{
    HINSTANCE hThisInstance = GetModuleHandle(NULL) ;
    int nFunsterStil = SW_SHOW ;
    HWND hWnd; /* 这是窗口的句柄 */
    MSG messages;/* 应用程序的消息保存在这里 */
    WNDCLASSEX wincl;/* 窗口类的数据结构 */
    /* 窗口结构 */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;/* 这个函数由Windows操作系统调用 */
    wincl.style = CS_DBLCLKS; /* 获取双击指令 */
    wincl.cbSize = sizeof (WNDCLASSEX);
    /* 使用默认图标和鼠标指针 */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL; /* 没有菜单 */
    wincl.cbClsExtra = 0;/* 窗口类后面没有多余的字节 */
    wincl.cbWndExtra = 0;/* 结构或者窗口实例 */
    /* 使用窗口的默认颜色作为窗口的背景色 */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    /* 注册窗口类。如果注册失败，那么就退出程序 */
    if (!RegisterClassEx (&wincl))
        return 0;
    /* 窗口类已被注册。创建它的程序 */
    hWnd = CreateWindowEx (
            0,
            szClassName,    /* 类名 */
            TEXT("Windows App"),    /* 窗口标题栏的文字 */
            WS_OVERLAPPEDWINDOW, /* 默认窗口 */
            CW_USEDEFAULT, /* 窗口左上角的位置 */
            CW_USEDEFAULT, /* 窗口右下角的位置 */
            300, /* 窗口宽度（以“像素”位单位） */
            300, /* 窗口高度（以“像素”位单位） */
            HWND_DESKTOP,/* 窗口是桌面的子窗口 */
            NULL,/* 该窗口无菜单 */
            hThisInstance, /* 程序实例的句柄 */
            NULL /* 没有窗口创建的数据 */
            );
    /* 显示窗口 */
    ShowWindow (hWnd, nFunsterStil);
    /* 重绘窗口 */
    UpdateWindow(hWnd);
    /* 运行消息循环。循环到GetMessage()函数返回0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* 把虚拟信息翻译成字符信息 */
        TranslateMessage(&messages);
        /* 发送信息到窗口过程 */
        DispatchMessage(&messages);
    }
    /* 返回PostQuitMessage()函数的返回值 */
    return messages.wParam;
}