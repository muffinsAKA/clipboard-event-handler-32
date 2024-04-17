#include <iostream>
#include <windows.h>

// Function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int main() {
    const char* className = "ClipBoardListener";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = className;

    if (!RegisterClass(&wc)) {
        std::cerr << "RegisterClass failed!" << std::endl;
        return 1;
    }

    HWND hwnd = CreateWindowEx(0, className, "Clipboard Listener", 0,
                               0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
    if (!hwnd) {
        std::cerr << "Failed to create message window" << std::endl;
        return 1;
    }

    if (!AddClipboardFormatListener(hwnd)) {
        std::cerr << "Failed to add clipboard format listener" << std::endl;
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    RemoveClipboardFormatListener(hwnd);
    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CLIPBOARDUPDATE:
        std::cout << "CLIPBOARD_CHANGE" << std::endl;
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
