import sys
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QColor, QFont, QPixmap
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QHBoxLayout, QSpacerItem, QSizePolicy

# 需要images文件夹作为图片目录，可以修改为其他的

class GradientWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('/(ㄒoㄒ)/~~')

        # 主布局，水平布局
        main_layout = QHBoxLayout()
        main_layout.setSpacing(0)  # 无间距
        main_layout.setContentsMargins(0, 0, 0, 0)  # 无外边距

        # 添加左侧空白页面
        self.create_left_panel(main_layout)

        # 添加右侧工具页面
        self.create_right_panel(main_layout)

        # 设置主布局
        self.setLayout(main_layout)
        self.setGeometry(100, 100, 600, 350)

    def create_left_panel(self, layout):
        """创建左侧正方形页面，显示 logo 和三个图标"""
        left_panel = QWidget()
        left_panel.setFixedWidth(200)  # 设置固定宽度
        left_panel.setStyleSheet("background-color: white;")  # 背景为白色

        # 在左侧页面中添加布局
        left_layout = QVBoxLayout()
        left_layout.setContentsMargins(10, 10, 10, 10)
        left_layout.setSpacing(20)  # 控件间距

        # 加载 logo 图片
        logo_label = QLabel()
        pixmap = QPixmap("images/logo.png")
        if not pixmap.isNull():  # 确保图片成功加载
            scaled_pixmap = pixmap.scaled(120, 120, Qt.KeepAspectRatio, Qt.SmoothTransformation)  # 缩放图片
            logo_label.setPixmap(scaled_pixmap)
        else:
            logo_label.setText("未找到 logo.png")
            logo_label.setAlignment(Qt.AlignCenter)
            logo_label.setStyleSheet("color: red; font-size: 16px;")

        # 上部添加空白，调整 logo 向上
        left_layout.addWidget(logo_label, alignment=Qt.AlignTop | Qt.AlignHCenter)

        # 添加三个图标
        icons_layout = QHBoxLayout()
        icons_layout.setSpacing(10)  # 图标间距

        for i in range(1, 4):  # 添加三个图标
            icon_label = QLabel()
            icon_pixmap = QPixmap(f"images/icon{i}.png")
            if not icon_pixmap.isNull():
                scaled_icon = icon_pixmap.scaled(40, 40, Qt.KeepAspectRatio, Qt.SmoothTransformation)
                icon_label.setPixmap(scaled_icon)
            else:
                icon_label.setText(f"图标{i}")
                icon_label.setAlignment(Qt.AlignCenter)
                icon_label.setStyleSheet("color: gray; font-size: 12px;")
            icons_layout.addWidget(icon_label, alignment=Qt.AlignCenter)

        left_layout.addLayout(icons_layout)  # 添加图标布局到左侧

        # 添加左侧布局到面板
        left_panel.setLayout(left_layout)
        layout.addWidget(left_panel)

    def create_right_panel(self, layout):
        """创建右侧工具页面"""
        right_panel = QWidget()

        # 设置右侧页面的总体布局
        layout_right = QVBoxLayout()
        layout_right.setSpacing(0)
        layout_right.setContentsMargins(0, 0, 0, 0)

        # 设置统一字体为黑体
        font = QFont("黑体", 18)  # 普通黑体
        title_font = QFont("黑体", 24, QFont.Bold)  # 标题字体

        # 添加标题
        title = QLabel("537工具箱")
        title.setFont(title_font)
        title.setAlignment(Qt.AlignLeft | Qt.AlignVCenter)
        title.setStyleSheet("color: white; background-color: red; padding-left: 10px;")
        title.setFixedHeight(60)
        layout_right.addWidget(title)

        # 定义每个部分的内容
        sections = ["系统", "网络", "存储", "文件", "更多"]
        colors = [
            QColor(255, 0, 0),     # 红色
            QColor(255, 69, 0),    # 橙红色
            QColor(255, 140, 0),   # 深橙色
            QColor(255, 165, 0),   # 橙色
            QColor(255, 215, 0)    # 金色
        ]

        # 添加各部分为按钮样式的标签
        for i, section in enumerate(sections):
            label = QLabel(section)
            label.setFont(font)
            label.setAlignment(Qt.AlignLeft | Qt.AlignVCenter)
            label.setStyleSheet(f"""
                color: white; 
                background-color: rgb({colors[i].red()}, {colors[i].green()}, {colors[i].blue()});
                padding-left: 10px;
            """)
            label.setFixedHeight(60)
            layout_right.addWidget(label)

        # 设置右侧页面的布局
        right_panel.setLayout(layout_right)
        layout.addWidget(right_panel)

# 初始化应用程序
app = QApplication(sys.argv)
window = GradientWindow()
window.show()
sys.exit(app.exec_())
