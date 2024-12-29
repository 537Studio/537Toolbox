import tkinter as tk
from PIL import Image, ImageTk


class WelcomeWindow(tk.Toplevel):

    def __init__(self, master: tk.Tk):
        super().__init__(master)

        self.wm_overrideredirect(True)
        x = (self.winfo_screenwidth() // 2) - 256
        y = (self.winfo_screenheight() // 2) - 128
        self.wm_geometry(f'512x256+{x}+{y}')
        self.wm_attributes("-topmost", True)
        self.configure(bg="#1e90ff")

        tk.Label(self, text="537 工具箱", bg="#1e90ff", fg="white",
                 font=("TkDefaultFont", 72, "bold")).pack(expand=1)

        self.alpha = 0
        self.fade_in()

    def fade_in(self):
        if self.alpha <= 1.0:
            self.alpha += 0.0175
            self.wm_attributes("-alpha", self.alpha)
            self.after(16, self.fade_in)
        else:
            self.after(750, self.fade_out)

    def fade_out(self):
        if self.alpha > 0:
            self.alpha -= 0.025
            self.wm_attributes("-alpha", self.alpha)
            self.after(16, self.fade_out)
        elif self.alpha == 0:
            self.destroy()


class GradientWindow(tk.Tk):

    version = 1.0

    def __init__(self):
        super().__init__()

        # Base attribtues setup
        self.wm_geometry("600x350+100+100")
        self.wm_title("/(ㄒoㄒ)/~~")
        self.focus_force()
        self.wm_attributes("-alpha", 0)

        self.welcome = WelcomeWindow(self)
        self.after(2500, self._fade_in)

        # Some variables defintion
        self.alpha = 0
        self.logo = ImageTk.PhotoImage(Image.open(
            "images/logo.png").resize((120, 120)))
        self.icons = []
        self.icon_cmds = [
            self._about,
            None,
            None
        ]
        self.label_objs: list[tk.Label] = []
        self.label_texts = [
            "537 工具箱",
            "系统",
            "网络",
            "存储",
            "文件",
            "更多"
        ]
        self.label_cmds = [
            self._about,
            None,
            None,
            None,
            None,
            None
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
        self.right_panel.pack_propagate(False)

        # Setup Images
        self._left_panel()
        # Setup Labels
        self._right_panel()

    def _fade_in(self):
        if self.alpha <= 1.0:
            self.alpha += 0.1
            self.wm_attributes("-alpha", self.alpha)
            self.after(16, self._fade_in)

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
            now_icon = tk.Label(icons_frame, image=self.icons[i-1], bg="white")
            now_icon.bind("<Button-1>", lambda _event,
                          index=i - 1: self.icon_cmds[index]())
            now_icon.pack(side="left", padx=10, expand=1)

    def _right_panel(self):
        for i in range(1, 7):
            now_label = tk.Label(self.right_panel, bg=self.colors[i-1], fg="white", font=(
                "TkDefaultFont", 22), text=self.label_texts[i-1], anchor="w", padx=20)
            now_label.bind("<Enter>", lambda _event, index=i -
                           1: self._label_enter(index))
            now_label.bind("<Leave>", lambda _event, index=i -
                           1: self._label_leave(index))
            now_label.bind("<Button-1>", lambda _event, index=i -
                           1: self.label_cmds[index]())
            now_label.pack(side="top", fill="both", expand=1)
            self.label_objs.append(now_label)

    def _label_enter(self, index):
        this = self.label_objs[index]
        colors = self._interpolate_color(
            this["bg"], self._hex_color(this["bg"]))

        def animate_color(i):
            if i < len(colors):
                this["bg"] = colors[i]
                self.after(8, lambda i=i + 1: animate_color(i))

        animate_color(0)

    def _label_leave(self, index):
        this = self.label_objs[index]
        colors = self._interpolate_color(this["bg"], self.colors[index])

        def animate_color(i):
            if i < len(colors):
                this["bg"] = colors[i]
                self.after(8, lambda i=i + 1: animate_color(i))

        animate_color(0)

    def _set_bg(self, widget: tk.Widget, color: str):
        widget["bg"] = color

    def _interpolate_color(self, start_color: str, end_color: str, steps=8) -> list:
        start_rgb = self._hex_to_rgb(start_color)
        end_rgb = self._hex_to_rgb(end_color)

        r_step = (end_rgb[0] - start_rgb[0]) / (steps - 1)
        g_step = (end_rgb[1] - start_rgb[1]) / (steps - 1)
        b_step = (end_rgb[2] - start_rgb[2]) / (steps - 1)

        interpolated_colors = []
        for i in range(steps):
            r = round(start_rgb[0] + i * r_step)
            g = round(start_rgb[1] + i * g_step)
            b = round(start_rgb[2] + i * b_step)

            interpolated_color = self._rgb_to_hex((r, g, b))
            interpolated_colors.append(interpolated_color)

        return interpolated_colors

    def _hex_color(self, color: str, factor=0.9):
        color = color.lstrip('#')
        r, g, b = [int(color[i:i+2], 16) for i in (0, 2, 4)]
        r = min(255, int(r * factor))
        g = min(255, int(g * factor))
        b = min(255, int(b * factor))
        hex = f"#{r:02x}{g:02x}{b:02x}"

        return hex

    def _hex_to_rgb(self, hex_color: str):
        hex_color = hex_color.lstrip('#')
        return tuple(int(hex_color[i:i+2], 16) for i in (0, 2, 4))

    def _rgb_to_hex(self, rgb_color: tuple[int, int, int]):
        return '#{:02x}{:02x}{:02x}'.format(*rgb_color)

    def _about(self):
        this = tk.Toplevel(self)
        this.wm_title("关于 537 工具箱")
        this.configure(bg="white", pady=20, padx=20)
        this.wm_resizable(False, False)
        self._center_top(this)

        tk.Label(this, image=self.logo, bg="white").pack(padx=50)
        tk.Label(this, text="537 工具箱", font=("TkDefaultFont",
                 16, "bold"), bg="white").pack(pady=[10, 0])
        tk.Label(this, text=f"版本{self.version}", bg="white").pack()
        tk.Label(this, text="Copyright © 2023-2024 537 Studio",
                 bg="white").pack(pady=[15, 0])

    def _center_top(self, toplevel: tk.Toplevel):
        x = int(self.winfo_x() + self.winfo_reqwidth() /
                2 - toplevel.winfo_reqwidth() / 2)
        y = int(self.winfo_y() + self.winfo_reqheight() /
                2 - toplevel.winfo_reqheight() / 2)
        toplevel.wm_geometry(f"+{x}+{y}")


if __name__ == "__main__":
    root = GradientWindow()
    root.mainloop()
