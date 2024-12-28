import tkinter as tk
from PIL import Image, ImageTk


class GradientWindow(tk.Tk):

    def __init__(self):
        super().__init__()

        # Base attribtues setup
        self.wm_geometry("600x350+100+100")
        self.wm_title("/(ㄒoㄒ)/~~")
        self.focus_force()

        # Some variables defintion
        self.logo = ImageTk.PhotoImage(Image.open(
            "images/logo.png").resize((120, 120)))
        self.icons = []
        self.labels = [
            "537 工具箱",
            "系统",
            "网络",
            "存储",
            "文件",
            "更多"
        ]
        self.colors = [
            "#ff0000",
            "#ff0000",
            "#ff4500",
            "#ff8c00",
            "#ffa500",
            "#ffd700"
        ]

        self.left_panel = tk.Frame(self, highlightthickness=0, bg="white")
        self.left_panel.pack(fill="both", side="left", expand=1)
        self.right_panel = tk.Canvas(self, highlightthickness=0, bg="white")
        self.right_panel.pack(fill="both", side="right", expand=1)

        # Setup Images
        self._left_panel()
        # Setup Labels
        self._right_panel()

        self.mainloop()

    def _left_panel(self):
        # Logo Image
        tk.Label(self.left_panel, image=self.logo,
                 bg="white").pack(side="top", pady=20)
        tk.Label(self.left_panel, text="537工具箱",
                 font=("TkDefaultFont", 20), bg="white").pack()
        # Three Icons
        icons_frame = tk.Frame(
            self.left_panel, highlightthickness=0, bg="white")
        icons_frame.pack(side="bottom", pady=50)
        for i in range(1, 4):
            self.icons.append(ImageTk.PhotoImage(
                Image.open(f"images/icon{i}.png").resize((40, 40))))
            tk.Label(
                icons_frame, image=self.icons[i-1], bg="white").pack(side="left", padx=10, expand=1)

    def _right_panel(self):
        for i in range(1, 7):
            tk.Label(
                self.right_panel, bg=self.colors[i-1], fg="white", font=("TkDefaultFont", 22), text=self.labels[i-1], anchor="w", padx=20).pack(side="top", fill="both", expand=1)


if __name__ == "__main__":
    root = GradientWindow()
