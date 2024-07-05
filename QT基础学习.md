# QT基础学习

## 1.简介

**qt是一个跨平台的c++图形用户界面应用程序框架。它为应用程序开发者提供建立图形界面所需的所有功能。它是完全面向对象的，很容易扩展，并且允许真正的组件编程。**

Qt的发展史

> 1991年，qt最早由芬兰奇趣科技开发
>
> 1996年，进入商业领域，它也是目前流行的linux桌面环境KDE的基础
>
> 2008年，奇趣科技被诺基亚收购，QT成为诺基亚1旗下的编程基础
>
> 2012年，QT又被dialog公司收购
>
> 2014年，跨平台的集成开发环境qt creator3.1.0发布，同年5月20日配发了qt5.3正式版，至此qt实现了对ios，android，wp等各平台的全面支持

Qt的优势

> 1.跨平台，几乎支持所有的平台
>
> 2.借口简单，容易上手，学习qt框架对学习其他框架有参考意义
>
> 3.一定程度上简化了内存回收机制
>
> 4.开发效率高，能够快速的构建应用程序
>
> 5.有很好的社区氛围，市场份额在缓慢上升
>
> 6.可以进行嵌入式开发

新建一个qt项目，系统会默认给我们添加main.cpp,mywidget.cpp,mywidget.h和一个.pro项目文件，点击完成，即可创建一个qt桌面程序

## 2.一个最简单的Qt应用程序

### 2.1main函数中

```qt
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}

```

解释：

> 1.Qt系统提供的类头文件没有.h后辍
>
> 2.Qt一个类对应一个头文件，类名和头文件名一致
>
> 3.QApplication应用程序类
>
> ​          管理图形用户界面应用程序的控制类和主要设置。
>
> ​          是QT生命，一个程序要确保一直运行，就肯定至少有一个循环，这就是qt主消息循环，在其中完成来自窗口系统和其它资源的所有事件消息处理和调度。它也处理应用程序的初始化和结束，并且提供对话管理。
>
> ​         对于任何一个使用qt的图形用户界面应用程序，都正好存在一个QApplication对象，不论这个应用程序在同一时刻有多个窗口。
>
> 4.a.exec()
>
> ​      程序进入消息循环，等待对用户输入进行响应，这里main()把控制权控制权转交给qt，qt完成事件处理工作，当应用程退出的时候exec（）的值就会返回。在exec()中，Qt接受并处理用户和系统的事件并且把它们传递给适当的窗口部件。

### 2.2 .pro文件

> .pro就是工程文件，它是qmake自动生成的用于生产makefile的配置文件。类似于Vs中.sln和vsproj文件

以下是.pro文件的一个案例：

```
#引入Qt的模块，core gui
QT       += core gui
#如果qt版本大于4，那么引入widgets模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#生成最终文件的文件名，可执行文件exe
TARGET = 01_MyWidget
#项目类型，生成什么类型的文件，可执行程序还是库文件
TEMPLATE = app
#要编译的源文件列表
SOURCES += \
        main.cpp \
        mywidget.cpp
#要编译的头文件列表
HEADERS += \
        mywidget.h
```

### 2.3 命名规范

> 类名：单词首字母大写，单词和单词之间直接连接，无需连接字符。

```
MyClass，QPushButton
		class MainWindow
```

 Qt中内置的类型，头文件和类文件名同名

```
#include <Qstring>
          Qstring str;
          #include <QWidget>
          QWidget w;
```

> 函数名字，数量名：首字母小写，之后每个单词首字母大写，单词和单词之间直接连接，无需链接字符

```
//普通成员变量设置和获取
		void setText(QString text);
		QString text()const;
		//bool的成员变量设置和获取
		void setEnabled(bool enabled);
		bool isEnabled()const;
```

### 2.4 QtCreator宠用快捷键

```
运行 ctrl+R
编译 ctrl+B
帮助文档 F1，点击F1两次跳到帮助文档
跳到符号定义F2或者ctrl + 鼠标点击
注释 ctrl+/
整行移动代码 ctrl + shift+ ↑或↓
自动对齐 ctrl +i
同名之间的.h和cpp文件跳转F4
```

## 3.Qt按钮小程序

### 3.1按钮的创建和父子关系

在qt应用程序中，最常用的控件之一就是按钮了，首先我们来看一下如何创建一个按钮

```qt
#include <QPushButton>
{  QPushButton * btn = new QPushButton;
    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("德玛西亚");
    //移动位置
    btn->move(100,100);
    //第二种创建
    QPushButton * btn2 = new QPushButton("艾欧尼亚",this);
    //重新制定窗口大小
    this->resize(600,400);
    //设置窗口标题
    this->setWindowTitle("欢迎来到英雄联盟");
    //设置窗口大小
    this->setFixedSize(600,400);
  QPushButton * btn = new QPushButton;
    //设置父亲
    btn->setParent(this);
    //设置文字
    btn->setText("德玛西亚");
    //移动位置
    btn->move(100,100);
    //第二种创建
    QPushButton * btn2 = new QPushButton("艾欧尼亚",this);
    //重新制定窗口大小
    this->resize(600,400);
    //设置窗口标题
    this->setWindowTitle("欢迎来到英雄联盟");
    //设置窗口大小
    this->setFixedSize(600,400);}
```

> 上面代码中，一个按钮其实就是一个QpushButton类的对象，如果只是创建对象，是无法显示到窗口中的，所以我们需要依赖一个父窗口，也就是指定一个父亲，利用setParent函数或者创建对象的时候通过构造函数传参，此时我们就称两个窗口建立了父子关系，在有父窗口的情况下，窗口调用show会显示在父窗口中，如果没有父窗口，那么窗口调用show显示的会是一个顶层的窗口（顶层窗口是能够在任务栏中找到的，不依赖于任何一个窗口而独立存在）（按钮也是继承于QWidget，也属于窗口）。
>
> 如果想设置按钮上显示的文字可以用setText，移动按钮位置用move
>
> 对于窗口而言，我们可以修改左上角窗口的标题setWindowTitle，重新指定窗口大小resize，或者设置固定的窗口大小setFixedSize

### 3.2 Qt窗口坐标体系

​          通过以上代码可以看出Qt的坐标体系

​          以左上角为原点（0,0），以向右的方向为x轴的正方向，以向下为y轴的正方向

![img](https://img-blog.csdnimg.cn/a5aa3cb343064ba38dea4959cfaa9a62.png)****

> 对于嵌套窗口，其坐标是相对于父窗口来说的。顶层窗口的父窗口就是屏幕

### 对象树模型

> QObject是Qt里面绝大部分类的根类
>
> 1.QObject对象之间是以对象树的形式组织起来的
>
> ​      当两个QObject（或子类的对象）建立了父子关系的时候。子对象就会加入到父对象的一个成员变量叫children的list中。
>
> ​     当父对象析构的时候，这个列表中的所有对象也会被析构。（注意：这里说的是父对象和子对象，不要理解成父类和子类）
>
> 2.QWidget是能够在屏幕上显示的一切组件的父类。
>
>   QWidget继承自QObject，因此也继承了这种对象树关系，一个孩子自动地成为父组件的一个子组件。我们向某个窗口中添加一个按钮或其他控件（建立父子关系），当用户关闭这个窗口的时候，该窗口就会被析构，之前添加到它上面的按钮和其他控件也会被一同析构。这个结果也是我们开发人员所期望的。
>
>   当然，我们也可以手动删除子对象，当子对象析构的时候会发出一个信号destroyed，父对象收到这个信号之后会从children列表中剔除。比如，当我们删除了一个按钮是，其所在的主窗口会自动的将该按钮从其子对象列表中剔除，并且自动调整屏幕显示，按钮在屏幕上消失。当这个窗口西沟的时候，children列表里边已经没有这个按钮子对象，所以我们手动删除也不会引起程序错误。
>
> 3.对象树中的顺序是没有定义的，这意味着，销毁这些对象的顺序也是为定义的。
>
> 4.任何对象树中的QObject对象delete的时候，如果这个对象有parent,则自动将其从 parent的children（）列表中删除；如果有孩子，则自动删除每一个孩子。Qt保证没有QObject会被delete两次，这是有析构顺序决定的。

如果QObject在栈上创建，Qt 保持同样的行为。正常情况下，这也不会发生什么问题。来看下下面的代码片段：

```c++
{
    QWidget window;
    QPushButton quit("Quit", &window);
}
```

作为父组件的 window 和作为子组件的 quit 都是QObject的子类（事实上，它们都是QWidget的子类，而QWidget是QObject的子类）。这段代码是正确的，quit 的析构函数不会被调用两次，因为标准 C++要求，局部对象的析构顺序应该按照其创建顺序的相反过程。因此，这段代码在超出作用域时，会先调用 quit 的析构函数，将其从父对象 window 的子对象列表中删除，然后才会再调用 window 的析构函数。

但是，如果我们使用下面的代码：

```
{
    QPushButton quit("Quit");
    QWidget window;
    quit.setParent(&window);
}
```

情况又有所不同，析构顺序就有了问题。我们看到，在上面的代码中，作为父对象的 window 会首先被析构，因为它是最后一个创建的对象。在析构过程中，它会调用子对象列表中每一个对象的析构函数，也就是说， quit 此时就被析构了。然后，代码继续执行，在 window 析构之后，quit 也会被析构，因为 quit 也是一个局部变量，在超出作用域的时候当然也需要析构。但是，这时候已经是第二次调用 quit 的析构函数了，C++ 不允许调用两次析构函数，因此，程序崩溃了。

 由此我们看到，Qt 的对象树机制虽然帮助我们在一定程度上解决了内存问题，但是也引入了一些值得注意的事情。这些细节在今后的开发过程中很可能时不时跳出来烦扰一下，**所以，我们最好从开始就养成良好习惯，在 Qt 中，尽量在构造的时候就指定 parent 对象，并且大胆在堆上创建。**

## 4.信号和槽机制

> 信号：各种事件
>
> 槽：响应信号的动作
>
> 当某个事件发生后，如某个按钮被点击了一下，它就会发出一个被点击的信号（signal）。
>
> 某个对象接收到这个信号之后，就会做一些相关的处理动作（称为槽slot）。
>
> 但是Qt对象不会无故地收到某个信号，要想让一个对象接收到另一个对象发出的信号，这个时候需要建立连接（connect）

### 4.1 系统自带的信号和槽

下面我们完成一个小功能，上面我们已经学习到了按钮的创建，但是还没有体现出来按钮的功能，按钮最大的功能就是点击后出发一些事情，比如点击按钮，就把当前的窗口给关闭掉。那么在qt中我们应该如何实现

两行代码就可以搞定

```qt
 QPushButton * qb = new QPushButton("关闭",this);
 connect(qb,QPushButton::clicked,this,&Widget::close);
```

第一行是创建一个关闭按钮，这个之前学过，第二行就是核心了。也就是信号槽的使用方式

connect函数建立信号大宋这，信号，信号接收者，槽四者之间函数的关系

connect（sender，signal。receiver,slot）;

> sender:信号发送者
>
> signal：信号
>
> receiver：信号接收者
>
> slot:接受对象在接受到对象之后所需要调用的函数（槽函数）

这里要注意的就是connect的四个参数都是指针，信号和槽都是函数指针。

系统自带的信号和槽如何查找呢。这个就需要利用帮助文档了，在帮助文档中输入QPushButton,首先我们可以在Contents中寻找关键词signals，信号的意思，但是我们发现并没有找到。这时候我们就应该想到这个信号的被父类继承下来的，因此我们去他的父类QAbstractBuutton就可以找到，点击signals索引到系统自带的信号有如下几个。

![0fbf511cbd7943b99f39eeaf90ed06f7.png](https://img-blog.csdnimg.cn/0fbf511cbd7943b99f39eeaf90ed06f7.png)

这里的clicked就是我们要找的，槽函数的寻找方式和信号一样，只不过他的关键字是slot。

### 4.2 自定义信号和槽

> Qt框架默认提供的标准信号不足以完成我们的日常开发的需求，比如说点击某个按钮让另一个按钮的文字改变，这时候标准信号和槽就没有提供这样的函数。但是Qt信号和槽机制提供了允许我们自己设计自己的信号和槽

#### 4.2.1 自定义信号使用条件

> 1.声明在类的signals域下
>
> 2.没有返回值，void类型的函数
>
> 3.只有函数声明，没有定义
>
> 4.可以有参数，可以重载
>
> 5.通过emit关键字来触发信号，形式：emit object->sig(参数)

#### 4.2.2自定义槽函数使用条件

> 1.qt5之后可以声明在public下，同时还可以是静态的成员函数，全局函数，lambda表达式
>
> 2.没有返回值，void类型的函数
>
> 3.不仅有声明，还要有实现
>
> 4可以有参数可以重载

#### 4.2.3 使用自定义信号和槽

定义场景：下课了，老师跟同学说肚子饿了（信号），学生请老师吃饭（槽）

首先定义一个学生类和老师类

老师类中声明信号 饿了 hungry

```
signals:
       void hungry();
```

学生类中声明槽 请客treat

```
public :
       void treat();
```

在窗口类中声明一个公共方法下课，这个方法会触发老师饿了这个信号。而响应槽函数学生请客

```
	void MyWidget::ClassIsOver()
{
    //发送信号
    emit teacher->hungry();
}
```

学生响应了槽函数，并且打印信息

//自定义槽函数 实现

```
void Student::treat()
{
       qDebug() << "Student treat teacher";
}
```

在窗口中链接信号和槽

```
 teacher = new Teacher(this);
    student = new Student(this);
    connect(teacher,&Teacher::hungury,student,&Student::treat);
```

并且调用下课函数，测试打印相应的log

自定义的信号hungry带参数，需要提供重载的自定义信号和自定义槽

```qt
void hungry(QString name);  自定义信号
void treat(QString name );    自定义槽
但是由于有两个重名的自定义信号和自定义的槽，直接连接会报错，所以需要利用函数指针来指向函数地址， 然后在做连接
void (Teacher:: * teacherSingal)(QString) = &Teacher:: hangry;
void (Student:: * studentSlot)(QString) = &Student::treat;
```

### 4.3 信号和槽的扩展

> 1.一个信号可以连接多个槽
>
> 如果这种情况，这些槽会被一个一个的被调用，但是槽函数的调用顺序是不确定的，像上面的例子，可以将一个按钮点击信号连接到关闭信号的槽函数，同时也可以连接到学生请老师吃饭的槽函数上，点击按钮的时候可以看到关闭窗口的同时也学生清老师吃饭的log也打印出来
>
> 2.多个信号可以连接一个槽
>
> 只要任意一个信号发出，这个槽就会被调用。如：一个窗口多个按钮都可以关闭这个窗口。
>
> 3.一个信号可以连接到另外一个信号
>
> 当一个信号发出时，第二个信号被发出，这种信号-信号的形式和信号-槽的形式没有什莫区别，注意这里还是使用connect函数，只是信号的接受者和槽函数换成另外一个信号的发送者和信号函数。如上面的老师饿了的例子，可以新建一个按钮btn。
>
> ```
> connect(btn,&QPushButton::clicked,teacher,&Teacher::hungry);
> ```
>
> 4.信号和槽可以断开连接
>
> 可以使用disconnect函数，当初建立时connect怎末填的，disconnect就怎末填，这种情况并不常见，因为当一个对象delete之后，qt自动取消所有连接到这个对象上的槽
>
> 5.信号和槽函数类型和个数必须同时满足两个条件
>
> ​    信号函数的参数个数必须大于等于槽函数的参数个数
>
>  信号函数的参数类型和槽函数的参数类型必须一一对应

### 4.4 lambda表达式

C++11中的Lambda表达式用于定义匿名的函数对象，以简化编程工作。首先看一下Lambda表达式的基本构成：

        分为四个部分：[局部变量捕获列表]、（函数参数）、函数额外属性设置opt、函数返回值->retype、{函数主体}

[capture](parameters) opt ->retType
{
    ……;
}
#### 4.5.1 局部变量引入方式
​        [ ]，标识一个Lambda的开始。由于lambda表达式可以定义在某一个函数体A里边，所以lambda表达式有可能会去访问A函数中的局部变量。中括号里边内容是描述了在lambda表达式里边可以使用的外部局部变量的列表：

        []
    
            表示lambda表达式不能访问外部函数体的任何局部变量
    
        [a]
    
            在函数体内部使用值传递的方式访问a变量
    
        [&b]
    
            在函数体内部使用引用传递的方式访问b变量
    
        [=]
    
            函数外的所有局部变量都通过值传递的方式使用, 函数体内使用的是副本
    
        [&]
    
            引用的方式使用lambda表达式外部的所有变量
    
        [=, &foo]
    
            foo使用引用方式, 其余是值传递的方式
    
        [&,foo]
    
            foo使用值传递方式, 其余是引用传递的方式
    
         [this]
    
           在函数内部可以使用类的成员函数和成员变量，=和&形式也都会默认引入
    
        由于引用方式捕获对象会有局部变量释放了而lambda函数还没有被调用的情况。如果执行lambda函数那么引用传递方式捕获进来的局部变量的值不可预知。
    
        所以在无特殊情况下建议使用[=](){}的形式

#### 4.5.2 函数参数
​        (params)表示lambda函数对象接收的参数，类似于函数定义中的小括号表示函数接收的参数类型和个数。参数可以通过按值（如：(int a,int b)）和按引用（如：(int &a,int &b)）两种方式进行传递。函数参数部分可以省略，省略后相当于无参的函数。

#### 4.5.3 选项 Opt
​        Opt 部分是可选项，最常用的是mutable声明，这部分可以省略。外部函数局部变量通过值传递引进来时，其默认是const，所以不能修改这个局部变量的拷贝，加上mutable就可以

int a = 10 ;
[=]()
{
    a=20;//编译报错，a引进来是const
}

[=]()mutable
{
    a=20;//编译成功
};
#### 4.5.4 函数返回值 ->retType
​        ->retType，标识lambda函数返回值的类型。这部分可以省略，但是省略了并不代表函数没有返回值，编译器会自动根据函数体内的return语句判断返回值类型，但是如果有多条return语句，而且返回的类型都不一样，编译会报错，如：

[=]()mutable
{
    int b = 20;
    float c = 30.0;
    if(a>0)
        return b;
    else
        return c;//编译报错，两条return语句返回类型不一致
};
4.5.5 是函数主体{}
        {}，标识函数的实现，这部分不能省略，但函数体可以为空。

#### 4.5.6 槽函数使用 Lambda 表达式
以QPushButton点击事件为例：

connect(btn,&QPushButton::clicked,[=](){
        qDebug()<<"Clicked";
});
        这里可以看出使用Lambda表达式作为槽的时候不需要填入信号的接收者。当点击按钮的时候，clicked信号被触发，lambda表达式也会直接运行。当然lambda表达式还可以指定函数参数，这样也就能够接收到信号函数传递过来的参数了。

        由于lambda表达式比我们自己自定义槽函数要方便而且灵活得多，所以在实现槽函数的时候优先考虑使用Lambda表达式。一般我们的使用习惯也是lambda表达式外部函数的局部变量全部通过值传递捕获进来，也就是:
        [=](){  }的形式

## 5.QMainWindow

> QMainWindow是一个为用户提供主窗口的类，包括一个菜单栏（menu bar）,多个工具栏（tool bars），多个停靠部件（dock widgets），一个状态栏（status bar）以及一个中心部件（central widget），是许多应用程序的基础，如文本编辑器，图片编辑器等。

### 5.1菜单栏

一个窗口最多只有一个菜单栏，位于主窗口顶部，主窗口标题栏下面．

```qt
   #include <QMenuBar>
   ui->setupUi(this);
     //创建一个菜单栏
      QMenuBar * bar      = menuBar();
      // 将菜单栏放入到窗口中
      setMenuBar(bar);
      //新建菜单项
     QMenu * fileMenu = bar->addMenu("文件");
     QMenu * editMenu = bar->addMenu("编辑");
     //添加操作
     fileMenu->addAction("新建");
     fileMenu->addSeparator();
     fileMenu->addAction("打开");
```

> Qt 并没有专门的菜单项类，只是使用一个QAction类，抽象出公共的动作。当我们把QAction对象添加到菜单，就显示成一个菜单项，添加到工具栏，就显示成一个工具按钮。用户可以通过点击菜单项、点击工具栏按钮、点击快捷键来激活这个动作。

### 5.2工具栏

主窗口的工具栏可以有多个工具条，通常一个菜单对应一个工具条的方式，也可以根据需要进行工具条的划分。

1.调用QMainWindowd对象的成员函数addToolBar（）,该函数每次调用都会创建一个新的工具栏，并且返回该工具栏的指针。

 2.插入属于工具条的项，这时工具条上添加项也是用QAction。通过QToolBar类的addAction函数添加。

 3.工具条是一个可移动的窗口，它的停靠区域由QToolBar的allowAreas决定，包括（以下值可以通过查帮助文档allowAreas来索引到）。

```
#include <QToolBar>
     //工具栏
      QToolBar * toolBar= new QToolBar(this);
      addToolBar(Qt::LeftToolBarArea,toolBar);
      toolBar->addAction(q1);
      toolBar->addAction(q2);

```

### 5.3 状态栏

一个QMainWindow的程序最多只有一个状态栏。QMainWindow中可以有多个的部件都使用add…名字的函数，而只有一个的部件，就直接使用获取部件的函数，如menuBar。同理状态栏也提供了一个获取状态栏的函数statusBar()，没有就自动创建一个并返回状态栏的指针。

```
#include <QStatusBar>
#include <QLabel>
    //状态栏
    QStatusBar * statusbar = statusBar();
    setStatusBar(statusbar);
    QLabel * lable = new QLabel("提示信息",this);
    statusbar->addWidget(lable);
```

### 5.4 停靠部件

停靠部件 QDockWidget，也称浮动窗口，可以有多个。

```
QDockWidget * dock = new QDockWidget("标题",this);
//添加停靠部件到mainWindow中，并且设定默认停靠在左边
addDockWidget(Qt::LeftDockWidgetArea,dock);
//设定停靠部件允许停靠的范围
dock->setAllowedAreas(Qt::LeftDockWidgetArea |
Qt::RightDockWidgetArea | Qt::TopDockWidgetArea); 
```

### 5.5 核心部件

 除了以上几个部件，中心显示的部件都可以作为核心部件，例如一个记事本程序中，就是一个QTextEdit（编辑框控件）做核心部件

```qt
QTextEdit * edit = new QTextEdit(this);
//设置mainWindow的核心部件
setCentralWidget(edit);
```

### 5.6 使用UI文件创建窗口

创建工程的时候把UI文件留着

#### 5.6.1 UI设计窗口介绍

![b5955fc4a308424fb93554147cdfc677.png](https://img-blog.csdnimg.cn/b5955fc4a308424fb93554147cdfc677.png)

#### 5.6.2 菜单栏

1.添加删除状态栏

默认情况下QMainWindow项目一创建就自带了菜单栏，可以在对象树窗口中，右键菜单栏对象，移除菜单栏：

![933c79aaf7e248d4ac95cbd5fb46dc75.png](https://img-blog.csdnimg.cn/933c79aaf7e248d4ac95cbd5fb46dc75.png)

删除后也可以创建菜单栏，此时在对象树中右键MainWindow对象，菜单里边会多了创建菜单栏的功能

![bf37c3ae0af542f9a7ce99a23af64222.png](https://img-blog.csdnimg.cn/bf37c3ae0af542f9a7ce99a23af64222.png)

2.添加菜单栏

 点击菜单栏的“在这里输入”可以输入一个菜单名字创建一个菜单。

![bd8fd32a2795445db3b201ce075ef2af.png](https://img-blog.csdnimg.cn/bd8fd32a2795445db3b201ce075ef2af.png)

![9d987fb3a86545e9b754dc570847a9f9.png](https://img-blog.csdnimg.cn/9d987fb3a86545e9b754dc570847a9f9.png)

在UI界面中添加菜单项只能用英文，因为此时会创建一个QAction对象，会用输入的值作为对象名，所以不能用中文，得添加后再属性窗口改中文。

![dc23cedeb04c4213ad9f092803e58da9.png](https://img-blog.csdnimg.cn/dc23cedeb04c4213ad9f092803e58da9.png)

4.添加多级菜单

![95d674e201bc4c689986d5fd455603ec.png](https://img-blog.csdnimg.cn/95d674e201bc4c689986d5fd455603ec.png)

![359b6f7a2dbe4f48bbe54c88b06c54ea.png](https://img-blog.csdnimg.cn/359b6f7a2dbe4f48bbe54c88b06c54ea.png)

#### 5.6.3工具栏

1.添加/删除工具栏

 删除工具栏方法和删除菜单栏方法一样，不过工具栏可以有多个，所以每次右键MainWindow对象，都可以看到添加工具栏的选项。

![1572e2ab3f9540c286d43abc18f088c0.png](https://img-blog.csdnimg.cn/1572e2ab3f9540c286d43abc18f088c0.png)

2.工具栏添加动作

新添加的QAction对象会在动作编辑器里找到（Action Editor），可以直接拖拽上来添加到工具栏里。

![af8db29bbe2845afaeb74d8488e18fcc.png](https://img-blog.csdnimg.cn/af8db29bbe2845afaeb74d8488e18fcc.png)

![c8bc26ee30674cad967c86f5305ad28f.png](https://img-blog.csdnimg.cn/c8bc26ee30674cad967c86f5305ad28f.png)

#### 5.6.4 状态栏

添加和删除状态栏的方法和删除菜单栏方法一样

状态栏添加左侧控件,右侧控件只能通过代码添加

#### 5.6.5 停靠部件

 从工具箱中拖出一个停靠部件就行。也可以像设定工具栏停靠范围一样，在停靠部件的属性窗口中设定他可以停靠的范围。

![ebbcb4759f30435d9bbe18044c0b4919.png](https://img-blog.csdnimg.cn/ebbcb4759f30435d9bbe18044c0b4919.png)****

#### 5.6.6 核心部件

UI文件窗口默认核心部件就是一个widget

![79102f51dd374ad4b9676ccb88841e39.png](https://img-blog.csdnimg.cn/79102f51dd374ad4b9676ccb88841e39.png)

### 5.7 UI管理

  使用UI文件创建界面很轻松很便捷，他的原理就是每次我们保存UI文件的时候，QtCreator就自动帮我们将UI文件翻译成C++的图形界面创建代码。可以通过以下步骤查看代码

​    到工程编译目录，一般就是工程同级目录下会生成另一个编译目录，会找到一个带ui_前缀跟ui文件同名的.h文件，这就是代码。

![5562e24671e543b3b502300dda2eabcb.png](https://img-blog.csdnimg.cn/5562e24671e543b3b502300dda2eabcb.png)

![2c790e363daf43f5b36b0e613a8b66f7.png](https://img-blog.csdnimg.cn/2c790e363daf43f5b36b0e613a8b66f7.png)

![2c790e363daf43f5b36b0e613a8b66f7.png](https://img-blog.csdnimg.cn/2c790e363daf43f5b36b0e613a8b66f7.png)

在项目MainWindow的构造函数中会调用这个函数来初始化窗口，其实这里边就是初始化我们的各个控件。

```qt

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //如果想要使用ui里边的控件对象
    //代码必须写在setupUi之下
    //否则ui各个控件没有初始化时使用会出问题
    ui->pushButton->setText("Hello");

}
```

### 5.8 UI文件下使用信号和槽

#### 5.8.1 转到槽

在UI编辑界面中使用信号和槽很方便，比如，拖出一个Button到窗口上，右键这个button，选择转到槽：

![81e51b98baf740b2832482d9662c9833.png](https://img-blog.csdnimg.cn/81e51b98baf740b2832482d9662c9833.png)

此时会出现这个控件（QPushButton）可以连接的各个信号，我们可以根据具体需求选中信号来创建一个连接这个信号的槽函数：

![e911496d47904bb9b652bf996c2ea4ec.png](https://img-blog.csdnimg.cn/e911496d47904bb9b652bf996c2ea4ec.png)

 以click(bool)信号为例，创建了一个槽函数

![4b194e9bd22243c3a58dffd04ed67eda.png](https://img-blog.csdnimg.cn/4b194e9bd22243c3a58dffd04ed67eda.png)

这个槽函数是QtCreator自动帮我们创建的，而且也使用生成C++代码的方式帮我们做好了连接，我们可以直接在这个函数体内实现功能就行。很方便，比使用Lambda表达式还方便。

#### 5.8.2 信号编辑器

可以使用动作编辑器旁边的信号槽编辑器，里边也可以添加信号和槽的连接，比如添加actionQuit的triggered信号和窗口close槽的连接：

![a71b385443384f4190eb30570d569d71.png](https://img-blog.csdnimg.cn/a71b385443384f4190eb30570d569d71.png)

#### 5.8.3 资源文件

>   Qt 资源系统是一个跨平台的资源机制，用于将程序运行时所需要的资源以二进制的形式存储于可执行文件内部。如果你的程序需要加载特定的资源（图标、文本翻译等），那么，将其放置在资源文件中，就再也不需要担心这些文件的丢失。也就是说，如果你将资源以资源文件形式存储，它是会编译到可执行文件内部。
>

添加资源路径

1.首先把要添加的资源文件夹放到目录中（通过explore项目将资源粘贴进去）、

2.在qt中添加资源文件夹，一般我们都用res来表示，编写资源前缀

3.记得进行编译

4.在代码中编写

```
ui->actionNew->setIcon(QIcon(":/images/1.jpg"));
```

**记得千万不要省了其中的冒号**!

## 6 Dialog对话框

>  对话框是 GUI 程序中不可或缺的组成部分。很多不能或者不适合放入主窗口的功能组件都必须放在对话框中，比如用于完成一次性任务的功能（如登录功能、选择某个文件打开、保存文件）。对话框通常会是一个顶层窗口，出现在程序最上层，用于实现短期任务或者简洁的用户交互。
>
>  Qt 中使用QDialog类实现对话框，但是声明一个QDilaog对象的时候，不管这个对话框对象跟哪个窗口建立了父子关系，当他显示出来的时候都还是一个顶层的窗口。
>
> ​    对话框分为模态对话框和非模态对话框。
>
> 

 1.模态对话框，当对话框打开时，不能操作同一个应用程序的其他窗口，只有当对话框关闭的时候才可以操作。

> 模态对话框很常见，比如“打开文件”功能。你可以尝试一下记事本的打开文件，当打开文件对话框出现时，我们是不能对除此对话框之外的窗口部分进行操作的

2.此相反的是非模态对话框，例如查找对话框，我们可以在显示着查找对话框的同时，继续对记事本的内容进行编辑

 模态对话框

```qt
#include <QDialog>
connect(ui->actionNew,&QAction::triggered,[=](){
        QDialog * dialog = new QDialog(this);
      dialog->setWindowTitle("模态对话框");
     dialog->resize(400,200);
       dialog->exec();
```

非模态对话框

```
 #include <QDialog>
 connect(ui->actionNew,&QAction::triggered,[=](){
        QDialog * dialog = new QDialog(this);
      dialog->setWindowTitle("非模态对话框");
     dialog->resize(400,200);
     dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
```

注：这里非模态对话框，当我们关闭这个窗口时，要执行这一步。当我们将主窗口作为 parent 时，主窗口不关闭，对话框就不会被销毁，所以会一直占用内存。在这种情景下，我们可以设置 dialog 的WindowAttribute。

```
dialog->setAttribute(Qt::WA_DeleteOnClose);
```

setAttribute()函数设置对话框关闭时，自动销毁对话框。

### 6.1  消息对话框

总共分为四类：错误，信息，问题。警告；

代码如下：

```qt
         //消息对话框

        //错误对话框
       QMessageBox::critical(this,"critical","错误");
        //信息对话框

       QMessageBox::information(this,"info","信息");

        //问题对话框
       QMessageBox::question(this,"question","问题",QMessageBox::Save|QMessageBox::Cancel);

        //警告对话框
       QMessageBox::warning(this,"warning","警告");
```

### 6.2文件对话框

代码如下

```
        QString str = QFileDialog::getOpenFileName(this,"打开文件","D:\\qt","*.txt");
        qDebug() << str;
```

> 1.parent：父窗口
>
> 2.caption：对话框标题
>
> 3.dir：对话框打开时的默认目录
>
>  “.” 代表程序运行目录
>
> ​    “/” 代表当前盘符的根目录（特指 Windows 平台；Linux 平台当然就是根目录），这个参数也可以是平台相关的，比如“C:\\”等；
>
> 4.filter：过滤器
>
> 我们使用文件对话框可以浏览很多类型的文件，但是，很多时候我们仅希望打开特定类型的文件。比如，文本编辑器希望打开文本文件，图片浏览器希望打开图片文件。过滤器就是用于过滤特定的后缀名。如果我们使用“Image Files(*.jpg *.png)”，则只能显示后缀名是 jpg 或者 png 的文件。如果需要多个过滤器，使用“;;”分割，比如“JPEG Files(*.jpg);;PNG Files(*.png)”；
>
> 5.selectedFilter：默认选择的过滤器；
>
> 6.options：对话框的一些参数设定
>
> 比如只显示文件夹等等，它的取值是enum QFileDialog::Option，每个选项可以使用 | 运算组合起来
>

## 7.布局

  所谓 GUI 界面，归根结底，就是一堆组件的叠加。我们创建一个窗口，把按钮放上面，把图标放上面，这样就成了一个界面。在放置时，组件的位置尤其重要。我们必须要指定组件放在哪里，以便窗口能够按照我们需要的方式进行渲染。这就涉及到组件布局定位的机制。

1.静态布局就是一种最原始的定位方法：给出这个组件的坐标和长宽值

        这样，Qt 就知道该把组件放在哪里以及如何设置组件的大小。但是这样做带来的一个问题是，如果用户改变了窗口大小，比如点击最大化按钮或者使用鼠标拖动窗口边缘，采用静态布局的组件是不会有任何响应的。这也很自然，因为你并没有告诉 Qt，在窗口变化时，组件是否要更新自己以及如何更新。或者，还有更简单的方法：禁止用户改变窗口大小。但这总不是长远之计。

2.动态布局：你只要把组件放入某一种布局(layout)，布局由专门的布局管理器进行管理。当需要调整大小或者位置的时候，Qt 使用对应的布局管理器进行调整。

        动态布局解决了使用静态布局的缺陷。
    
        Qt 提供的动态布局中以下三种是我们最常用的：
    
                1）QHBoxLayout：按照水平方向从左到右布局；
    
                2）QVBoxLayout：按照竖直方向从上到下布局；
    
                3）QGridLayout：在一个网格中进行布局，类似于 HTML 的 table；

7.1 系统提供的布局控件


         这4个为系统给我们提供的布局的控件，但是使用起来不是非常的灵活，这里就不详细介绍了。

7.2 利用 widget 做布局
        第二种布局方式是利用控件里的widget来做布局，在Containers中

![37106c1483714b52a6ff0120e749e07e.png](https://img-blog.csdnimg.cn/37106c1483714b52a6ff0120e749e07e.png)

## 8.常用控件

QLable是我们最常用的控件之一，其功能很强大，我们可以用来显示文本，图片和动画等。

### 8.1 QLable控件使用

#### 8.1.1 显示文字（普通文本，html）

通过QLable类的setText函数设置显示内容：

1.可以显示普通文本字符串

> QLable *label = new QLable;
> label->setText(“Hello, World!”);

2.可以显示HTML格式的字符串，比如显示一个链接

> QLabel * label = new QLabel(this);
> label ->setText("Hello, World");
> label ->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
> label ->setOpenExternalLinks(true);

其中setOpenExternalLinks()函数是用来设置用户点击链接之后是否自动打开链接，如果参数指定为true则会自动打开。

#### 8.1.2 显示图片

可以使用QLabel的成员函数setPixmap设置图片

void     setPixmap(const QPixmap &)

首先定义QPixmap对象

QPixmap pixmap;

然后加载图片

pixmap.load(":/Image/boat.jpg");

最后将图片设置到QLabel中

QLabel *label = new QLabel;

label.setPixmap(pixmap);

#### 8.1.3 显示动画

> 可以使用QLabel 的成员函数setMovie加载动画，可以播放gif格式的文件
>
> void     setMovie(QMovie * movie)
>
> 首先定义QMovied对象，并初始化:
>
> QMovie *movie = new QMovie(":/Mario.gif");
>
> 播放加载的动画：
>
> movie->start();
>
> 将动画设置到QLabel中：
>
> QLabel *label = new QLabel；
>
> label->setMovie(movie);
>

### 8.2 QLineEdit

>   Qt提供的单行文本编辑框。
>
>                 1.获取编辑框内容使用text（），函数声明如下：
>
> QString     text() const
>                 2.设置编辑框内容
>
> void	setText(const QString &)
> 
>

#### 8.2.2 设置显示模式

使用QLineEdit类的setEchoMode () 函数设置文本的显示模式,函数声明:

void     setEchoMode(EchoMode mode)
EchoMode是一个枚举类型,一共定义了四种显示模式:

        1.QLineEdit::Normal  模式显示方式，按照输入的内容显示。
    
        2.QLineEdit::NoEcho 不显示任何内容，此模式下无法看到用户的输入。
    
        3.QLineEdit::Password    密码模式，输入的字符会根据平台转换为特殊字符。
    
        4.QLineEdit::PasswordEchoOnEdit  编辑时显示字符否则显示字符作为密码。
    
        另外，我们再使用QLineEdit显示文本的时候，希望在左侧留出一段空白的区域，那么，就可以使用QLineEdit给我们提供的setTextMargins函数：

void setTextMargins(int left, int top, int right, int bottom)
用此函数可以指定显示的文本与输入框上下左右边界的间隔的像素数。

### 8.3 其他控件

QT中控件的使用方法可以参考Qt提供的帮助文档

### 8.4 自定义控件

在搭建Qt窗口界面的时候，在一个项目中很多窗口，或者是窗口中的某个模块会被经常性的重复使用。一般遇到这种情况我们都会将这个窗口或者模块拿出来做成一个独立的窗口类，以备以后重复使用。

        在使用Qt的ui文件搭建界面的时候，工具栏栏中只为我们提供了标准的窗口控件，如果我们想使用自定义控件怎么办？
![9ec50ab0a64b446787c9e5c854abb6fc.png](https://img-blog.csdnimg.cn/9ec50ab0a64b446787c9e5c854abb6fc.png)

 那么这个SmallWidget可以作为独立的窗口显示,也可以作为一个控件来使用：

​    打开Qt的.ui文件,因为SmallWidget是派生自Qwidget类,所以需要在ui文件中先放入一个QWidget控件, 然后再上边鼠标右键

![cf71768cc7844d168738c5652cde1f81.png](https://img-blog.csdnimg.cn/cf71768cc7844d168738c5652cde1f81.png)

弹出提升窗口部件对话框

![dffef2999f1e4be09d31b97543f1f20b.png](https://img-blog.csdnimg.cn/dffef2999f1e4be09d31b97543f1f20b.png)

添加要提升的类的名字,然后选择 添加

![dd56ece234c84b98800816edbbf5c442.png](https://img-blog.csdnimg.cn/dd56ece234c84b98800816edbbf5c442.png)

添加之后,类名会显示到上边的列表框中,然后单击提升按钮,完成操作.

我们可以看到, 这个窗口对应的类从原来的QWidget变成了SmallWidget

![527c43ad171e45a197f1e86eb2f3e3a2.png](https://img-blog.csdnimg.cn/527c43ad171e45a197f1e86eb2f3e3a2.png)

再次运行程序,这个widget_3中就能显示出我们自定义的窗口了.

代码 smallwidget.cpp 代码如下

```
    ui->setupUi(this);
 connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
    void (QSpinBox :: * sb)(int) = &QSpinBox :: valueChanged;
    connect(ui->spinBox,sb,ui->horizontalSlider,&QSlider::setValue);
```

## 9.Qt 消息事件机制

### 9.1 事件

>  事件（event）是由系统或者 Qt 应用程序本身在不同的时刻发出的。当用户按下鼠标、敲下键盘，或者是窗口需要重新绘制的时候，都会发出一个相应的事件。一些事件在对用户操作做出响应时发出，如键盘事件等；另一些事件则是由系统自动发出，如计时器事件。

### 9.2 事件处理函数

在所有组件的父类QWidget中，定义了很多事件处理的函数，如

```qt
    1.keyPressEvent()：键盘按键按下事件

    2.keyReleaseEvent()：键盘按键松开事件

    3.mouseDoubleClickEvent()：鼠标双击事件

    4.mouseMoveEvent()：鼠标移动事件

    5.mousePressEvent()：鼠标按键按下事件

    6.mouseReleaseEvent() ：鼠标按键松开事件

    7.等等
```
 这些函数都是 protected virtual 的，也就是说，我们可以在子类中重新实现这些函数。下面来看一个例子

```c++
class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};
 
void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Move: (%1, %2)</h1></center>").arg(QString::number(event->x()),
                          QString::number(event->y())));
}
 
void EventLabel::mousePressEvent(QMouseEvent *event)
{
    this->setText(QString("<center><h1>Press:(%1, %2)</h1></center>").arg(QString::number(event->x()),
                          QString::number(event->y())));
}
 
void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h1>Release: (%d, %d)</h1></center>",
                event->x(), event->y());
    this->setText(msg);
}
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    EventLabel *label = new EventLabel;
    label->setWindowTitle("MouseEvent Demo");
    label->resize(300, 200);
    label->show();
    
    return a.exec();
}
```

 1.EventLabel继承了QLabel，覆盖了mousePressEvent()、mouseMoveEvent()和MouseReleaseEvent()三个函数。我们并没有添加什么功能，只是在鼠标按下（press）、鼠标移动（move）和鼠标释放（release）的时候，把当前鼠标的坐标值显示在这个Label上面。由于QLabel是支持 HTML 代码的，因此我们直接使用了 HTML 代码来格式化文字。

        2.QString的arg()函数可以自动替换掉QString中出现的占位符。其占位符以 % 开始，后面是占位符的位置，例如 %1，%2 这种。

QString("[%1, %2]").arg(x).arg(y);
语句将会使用x替换 %1，y替换 %2，因此，生成的QString为[x, y]。       

        3.在mouseReleaseEvent()函数中，我们使用了另外一种QString的构造方法。我们使用类似 C 风格的格式化函数sprintf()来构造QString。
运行上面的代码，当我们点击了一下鼠标之后，label 上将显示鼠标当前坐标值。

![fe2bc3391a8e4193ba41cf330d510289.png](https://img-blog.csdnimg.cn/fe2bc3391a8e4193ba41cf330d510289.png)

为什么要点击鼠标之后才能在mouseMoveEvent()函数中显示鼠标坐标值？

        这是因为QWidget中有一个mouseTracking属性，该属性用于设置是否追踪鼠标。只有鼠标被追踪时，mouseMoveEvent()才会发出。如果mouseTracking是 false（默认即是），组件在至少一次鼠标点击之后，才能够被追踪，也就是能够发出mouseMoveEvent()事件。如果mouseTracking为 true，则mouseMoveEvent()直接可以被发出。

知道了这一点，我们就可以在main()函数中添加如下代码：

label->setMouseTracking(true);
在运行程序就没有这个问题了。 

### 9.3 事件分发函数

事件对象创建完毕后，Qt 将这个事件对象传递给QObject的event()函数。event()函数并不直接处理事件，而是将这些事件对象按照它们不同的类型，分发给不同的事件处理器（event handler）。

        如上所述，event()函数主要用于事件的分发。所以，如果你希望在事件分发之前做一些操作，就可以重写这个event()函数了。例如，我们希望在一个QWidget组件中监听 tab 键的按下，那么就可以继承QWidget，并重写它的event()函数，来达到这个目的：
## 10. 文件操作

文件操作是应用程序必不可少的部分。Qt 作为一个通用开发库，提供了跨平台的文件操作能力。在所有的 I/O 设备中，文件 I/O 是最重要的部分之一。因为我们大多数的程序依旧需要首先访问本地文件（当然，在云计算大行其道的将来，这一观点可能改变）。QFile提供了从文件中读取和写入数据的能力。

        我们通常会将文件路径作为参数传给QFile的构造函数。不过也可以在创建好对象最后，使用setFileName()来修改。QFile需要使用 / 作为文件分隔符，不过，它会自动将其转换成操作系统所需要的形式。例如 C:/windows 这样的路径在 Windows 平台下同样是可以的。

QFile主要提供了有关文件的各种操作，比如打开文件、关闭文件、刷新文件等。我们可以使用QDataStream或QTextStream类来读写文件，也可以使用QIODevice类提供的read()、readLine()、readAll()以及write()这样的函数。值得注意的是，有关文件本身的信息，比如文件名、文件所在目录的名字等，则是通过QFileInfo获取，而不是自己分析文件路径字符串。
文件操作是应用程序必不可少的部分。Qt 作为一个通用开发库，提供了跨平台的文件操作能力。在所有的 I/O 设备中，文件 I/O 是最重要的部分之一。因为我们大多数的程序依旧需要首先访问本地文件（当然，在云计算大行其道的将来，这一观点可能改变）。QFile提供了从文件中读取和写入数据的能力。

        我们通常会将文件路径作为参数传给QFile的构造函数。不过也可以在创建好对象最后，使用setFileName()来修改。QFile需要使用 / 作为文件分隔符，不过，它会自动将其转换成操作系统所需要的形式。例如 C:/windows 这样的路径在 Windows 平台下同样是可以的。

```c++
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QFile file("in.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Open file failed.";
        return -1;
    } else {
        while (!file.atEnd()) {
            qDebug() << file.readLine();
        }
    }
    
    QFileInfo info(file);
    qDebug() << info.isDir();
    qDebug() << info.isExecutable();
    qDebug() << info.baseName();
    qDebug() << info.completeBaseName();
    qDebug() << info.suffix();
    qDebug() << info.completeSuffix();
    
    return app.exec();
}
```

1.我们首先使用 QFile 创建了一个文件对象

        这个文件名字是 in.txt。如果你不知道应该把它放在哪里，可以使用QDir::currentPath()来获得应用程序执行时的当前路径。只要将这个文件放在与当前路径一致的目录下即可。

2.使用open()函数打开这个文件，打开形式是只读方式，文本格式。

        这个类似于fopen()的 r 这样的参数。open()函数返回一个 bool 类型，如果打开失败，我们在控制台输出一段提示然后程序退出。否则，我们利用 while 循环，将每一行读到的内容输出。

3.可以使用QFileInfo获取有关该文件的信息。

QFileInfo有很多类型的函数，我们只举出一些例子。比如：

                1）isDir() 检查该文件是否是目录（在操作系统这种，文件夹是一种特殊的文件，我们可以通过QFile来打开一个文件夹或者路径，这个函数返回值就是判断他是不是一个文件夹或路径）；
    
                2）isExecutable()  检查该文件是否可以被执行。
    
                3）baseName()           可以直接获得文件名；
    
                4）completeBaseName() 获取完整的文件名
    
                5）suffix()  则直接获取文件后缀名。
    
                6）completeSuffix()     获取完整的文件后缀
    
        我们可以由下面的示例看到，baseName()和completeBaseName()，以及suffix()和completeSuffix()的区别：

```
QFileInfo fi("/tmp/archive.tar.gz");
QString base  = fi.baseName();  // base = "archive"
QString base  = fi.completeBaseName();  // base = "archive.tar"
QString ext   = fi.suffix();  // ext = "gz"
QString ext   = fi.completeSuffix();  // ext = "tar.gz"
```

### 10.2 文本文件读写

```c++
上一节我们介绍了有关二进制文件的读写。二进制文件比较小巧，却不是人可读的格式。而文本文件是一种人可读的文件。为了操作这种文件，我们需要使用QTextStream类。QTextStream和QDataStream的使用类似，只不过它是操作纯文本文件的。

        QTextStream会自动将 Unicode 编码同操作系统的编码进行转换，这一操作对开发人员是透明的。它也会将换行符进行转换，同样不需要自己处理。QTextStream使用 16 位的QChar作为基础的数据存储单位，同样，它也支持 C++ 标准类型，如 int 等。实际上，这是将这种标准类型与字符串进行了相互转换。

```

  QTextStream同QDataStream的使用基本一致，例如下面的代码将把“The answer is 42”写入到 file.txt 文件中：

```
QFile data("file.txt");
    if (data.open(QFile::WriteOnly | QIODevice::Truncate)) 
    {
        QTextStream out(&data);
        out << "The answer is " << 42;
    }
```

这里，我们在open()函数中增加了QIODevice::Truncate打开方式。我们可以从下表中看到这些打开方式的区别：

    枚举值                                        描述

QIODevice::NotOpen            未打开
QIODevice::ReadOnly           以只读方式打开
QIODevice::WriteOnly           以只写方式打开
QIODevice::ReadWrite          以读写方式打开
QIODevice::Append               以追加的方式打开，新增加的内容将被追加到文件末尾 
QIODevice::Truncate             以重写的方式打开，在写入新的数据时会将原有
 QIODevice::Truncate            以重写的方式打开，在写入新的数据时会将原有      数据全部                                                   清除，游标设置在文件开头。
QIODevice::Text                 在读取时，将行结束符转换成 \n；在写入时，
将行结束符转换成本地格式，例如 Win32 平台上是 \r\n

QIODevice::Unbuffered 忽略缓存
        我们在这里使用了QFile::WriteOnly | QIODevice::Truncate，也就是以只写并且覆盖已有内容的形式操作文件。注意，QIODevice::Truncate会直接将文件内容清空。

        虽然QTextStream的写入内容与QDataStream一致，但是读取时却会有些困难：
```c++
 QFile data("file.txt");
    if (data.open(QFile::ReadOnly)) 
    {
        QTextStream in(&data);
        QString str;
        int ans = 0;
        in >> str >> ans;
    }
```

在使用QDataStream的时候，这样的代码很方便，但是使用了QTextStream时却有所不同：读出的时候，str 里面将是 The answer is 42，ans 是 0。这是因为当使用QDataStream写入的时候，实际上会在要写入的内容前面，额外添加一个这段内容的长度值。而以文本形式写入数据，是没有数据之间的分隔的。因此，使用文本文件时，很少会将其分割开来读取，而是使用诸如使用.

```
QTextStream::readLine();//读取一行
QTextStream::readAll();//读取所有文本
```

 这种函数之后再对获得的QString对象进行处理。

​    默认情况下，QTextStream的编码格式是 Unicode，如果我们需要使用另外的编码，可以使用：

stream.setCodec("UTF-8");

这样的函数进行设置。
