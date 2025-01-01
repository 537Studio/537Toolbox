import tkinter as tk
from PIL import ImageTk
import typing
import platform
import random


class BaseGraphics:

    def __init__(self) -> None:
        self.canvasId = ...


class PerfectCircle(BaseGraphics):

    def __init__(self, master: tk.Canvas, position: tuple[int | float, int | float],
                 radius: int | float, bg: str) -> None:
        super().__init__()
        self.master = master

        self.fill = bg

        self.x = position[0]
        self.y = position[1]
        self.radius = radius
        self.diameter = self.radius * 2

        self.canvasId = self.master.create_oval(
            self.x, self.y, self.x+self.diameter, self.y+self.diameter, fill=self.fill, outline=self.fill)

    def _bg(self, newBg: str):
        self.master.itemconfigure(self.canvasId, fill=newBg, outline=newBg)
        self.fill = newBg


class Rectangle(BaseGraphics):

    def __init__(self, master: tk.Canvas, position: tuple[int | float, int | float],
                 size: tuple[int | float, int | float], bg: str) -> None:
        super().__init__()
        self.master = master

        self.fill = bg

        self.x = position[0]
        self.y = position[1]
        self.width = size[0]
        self.height = size[1]

        self.canvasId = self.master.create_rectangle(
            self.x, self.y, self.x+self.width, self.y+self.height, fill=self.fill, outline=self.fill)

    def _position(self, newPosition: tuple[int | float, int | float]):
        self.master.coords(
            self.canvasId, newPosition[0], newPosition[1], newPosition[0]+self.width, newPosition[1]+self.height)
        self.x = newPosition[0]
        self.y = newPosition[1]

    def _bg(self, newBg: str):
        self.master.itemconfigure(self.canvasId, fill=newBg, outline=newBg)
        self.fill = newBg


class RoundedRectangle(BaseGraphics):

    def __init__(self, master: tk.Canvas, position: tuple[int | float, int | float],
                 size: tuple[int | float, int | float], radius: int | float, bg: str, bd: str | None = None) -> None:
        super().__init__()
        self.master = master
        self.fill = bg
        if not bd:
            self.outline = bd
        else:
            self.outline = self.fill
        self.radius = radius
        self.diameter = self.radius * 2

        self.x = position[0]
        self.y = position[1]
        self.width = size[0]
        self.height = size[1]
        self.roundedWidth = self.width - self.diameter
        self.roundedHeight = self.height - self.diameter

        self.__display()

    def bind(self, ids: list[PerfectCircle | Rectangle | int], sequence, func=None):
        for item in ids:
            if not isinstance(item, int):
                self.master.tag_bind(item.canvasId, sequence, func)
            else:
                self.master.tag_bind(item, sequence, func)

    def _bg(self, newBg: str):
        for Id in self.canvasId:
            if not isinstance(Id, int):
                try:
                    self.master.itemconfigure(
                        Id.canvasId, fill=newBg, outline=newBg)
                except:
                    self.master.itemconfigure(Id.canvasId, fill=newBg)
            else:
                try:
                    self.master.itemconfigure(Id, fill=newBg, outline=newBg)
                except:
                    self.master.itemconfigure(Id, fill=newBg)
        self.fill = newBg

    def _width(self, newWidth: int):
        self.master.delete(self.canvasId)
        self.width = newWidth
        self.__display()

    def __display(self):
        self.roundedWidth = self.width - self.diameter
        self.roundedHeight = self.height - self.diameter
        self.h1 = self.master.create_arc(
            self.x,
            self.y,
            self.x+self.diameter,
            self.y+self.diameter,
            start=90,
            style='arc',
            outline=self.outline
        )
        self.h2 = self.master.create_arc(
            self.x+self.width-self.diameter,
            self.y,
            self.x+self.width,
            self.y+self.diameter,
            start=0,
            style='arc',
            outline=self.outline
        )
        self.h3 = self.master.create_arc(
            self.x+self.width-self.diameter,
            self.y+self.height-self.diameter,
            self.x+self.width,
            self.y+self.height,
            start=270,
            style='arc',
            outline=self.outline
        )
        self.h4 = self.master.create_arc(
            self.x,
            self.y+self.height-self.diameter,
            self.x+self.diameter,
            self.y+self.height,
            start=180,
            style='arc',
            outline=self.outline,
        )
        self.o1 = self.master.create_line(
            self.x+self.radius+2,
            self.y,
            self.x+self.width-self.radius-2,
            self.y,
            fill=self.outline
        )
        self.o2 = self.master.create_line(
            self.x+self.width,
            self.y+self.radius+2,
            self.x+self.width,
            self.y+self.height-self.radius-2,
            fill=self.outline
        )
        self.o3 = self.master.create_line(
            self.x+self.radius+2,
            self.y+self.height,
            self.x+self.width-self.radius-2,
            self.y+self.height,
            fill=self.outline
        )
        self.o4 = self.master.create_line(
            self.x,
            self.y+self.radius+2,
            self.x,
            self.y+self.height-self.radius-2,
            fill=self.outline
        )
        self.c1 = PerfectCircle(
            self.master,
            [
                self.x,
                self.y
            ],
            self.radius,
            self.fill
        )
        self.c2 = PerfectCircle(
            self.master,
            [
                self.x,
                self.y+self.roundedHeight
            ],
            self.radius,
            self.fill
        )
        self.c3 = PerfectCircle(
            self.master,
            [
                self.x+self.roundedWidth,
                self.y+self.roundedHeight
            ],
            self.radius,
            self.fill
        )
        self.c4 = PerfectCircle(
            self.master,
            [
                self.x+self.roundedWidth,
                self.y
            ],
            self.radius,
            self.fill
        )
        self.r1 = Rectangle(
            self.master,
            [
                self.x,
                self.y+self.radius
            ], [
                self.diameter,
                self.roundedHeight
            ],
            self.fill
        )
        self.r2 = Rectangle(
            self.master,
            [
                self.x+self.radius,
                self.y+self.roundedHeight
            ], [
                self.roundedWidth,
                self.diameter
            ],
            self.fill
        )
        self.r3 = Rectangle(
            self.master,
            [
                self.x+self.roundedWidth,
                self.y+self.radius
            ], [
                self.diameter,
                self.roundedHeight
            ],
            self.fill
        )
        self.r4 = Rectangle(
            self.master,
            [
                self.x+self.radius,
                self.y
            ], [
                self.roundedWidth,
                self.diameter
            ],
            self.fill
        )
        self.mainr = Rectangle(
            self.master,
            [
                self.x+self.diameter,
                self.y+self.diameter
            ], [
                self.roundedWidth-self.diameter,
                self.roundedHeight-self.diameter
            ],
            self.fill
        )

        self.canvasId = [
            self.h1, self.h2, self.h3, self.h4,
            self.o1, self.o2, self.o3, self.o4,
            self.c1, self.c2, self.c3, self.c4,
            self.r1, self.r2, self.r3, self.r4, self.mainr
        ]


class Text(BaseGraphics):

    def __init__(self, master: tk.Canvas, position: tuple[int | float, int | float],
                 text: str, fg: str, *, placemode: typing.Literal['normal', 'usable'] = 'usable') -> None:
        super().__init__()
        self.master = master

        self.fill = fg
        self.placemode = placemode

        self.x = position[0]
        self.y = position[1]
        self.text = text

        self.canvasId = self.master.create_text(
            self.x, self.y, text=self.text, fill=self.fill)

        self.bbox = self.master.bbox(self.canvasId)
        self.width = self.bbox[2] - self.bbox[0]
        self.height = self.bbox[3] - self.bbox[1]

        if self.placemode == 'usable':
            self._usable()
        elif self.placemode != 'normal':
            raise ValueError(f"Uknown place mode: {self.placemode}")

    def _position(self, newPosition: tuple[int | float, int | float]):
        self.master.coords(self.canvasId, newPosition[0], newPosition[1])
        self.x = newPosition[0]
        self.y = newPosition[1]

    def _text(self, newText: str):
        self.master.itemconfigure(self.canvasId, text=newText)
        self.text = newText
        if self.placemode == 'usable':
            self._usable()

    def _fg(self, newFg: str):
        self.master.itemconfigure(self.canvasId, fill=newFg)
        self.fill = newFg

    def _usable(self):
        self.bbox = self.master.bbox(self.canvasId)
        self.width = self.bbox[2] - self.bbox[0]
        self.height = self.bbox[3] - self.bbox[1]

        self.master.coords(self.canvasId, self.x +
                           self.width/2, self.y+self.height/2)


class MessageBox(tk.Toplevel):

    def __init__(self, master: tk.Tk, title: str, text: tuple[str,], image: ImageTk.PhotoImage):
        super().__init__(master)

        self.wm_geometry(f"260x230+{int((self.winfo_screenwidth()-260)/2)}+{
                         int((self.winfo_screenheight()-240)/2)}")
        self.wm_overrideredirect(True)
        self.wm_attributes('-topmost', True)
        self.focus_force()

        self.canvas = tk.Canvas(
            self, highlightthickness=False)
        self.canvas.pack(fill='both', expand=1)

        self.frame = RoundedRectangle(
            self.canvas, [0, 0], [260, 230], 10, '#ffffff')

        self.image = image
        self.canvas.create_image(130, 52, image=self.image)

        self._title = Text(
            self.canvas, [130, 112], title, '#000000', placemode='normal')
        self.canvas.itemconfigure(
            self._title.canvasId, font=(None, 13, "bold"))
        self.text = tk.Label(self.canvas, text=text[0],
                             fg='#000000', anchor='center', bg='#ffffff', wraplength=228)
        self.canvas.create_window(
            130, 130+int(self.text.winfo_reqheight())/2, window=self.text)

        RoundedRectangle(self.canvas, [16, 188], [228, 28], 7.5, '#2174ff')
        Text(self.canvas, [130, 202], text[1],
                '#ffffff', placemode='normal')

        if not (platform.platform().startswith("macOS") or platform.platform() == 'Darwin'):
            this = self.random_color()
            self.configure(bg=this)
            self.canvas.configure(bg=this)
            self.wm_attributes('-transparentcolor', this)

            self.set_color()
        else:
            self.configure(bg='SystemTransparent')
            self.canvas.configure(bg='SystemTransparent')
            self.wm_attributes('-transparent', True)

        self.__opacity([0, 1])

    def random_color(self):
        colorArr = ['1', '2', '3', '4', '5', '6', '7',
                    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f']
        color = ""
        for i in range(6):
            color += colorArr[random.randint(0, 14)]
        return "#" + color

    def set_color(self):
        this = self.random_color()
        self.configure(bg=this)
        self.canvas.configure(bg=this)
        self.wm_attributes('-transparentcolor', this)
        self.after(500, self.set_color)

    def __opacity(self, alpha: tuple[int | float]):
        if alpha[1] <= 1.0:
            if self.tk:
                self.wm_attributes('-alpha', alpha[0])
                self.after(1000//60, self.__opacity,
                           [alpha[0] + 0.1, alpha[1]])
