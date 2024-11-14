# Java EE 第六次实习 SSM

|  课程   |  姓名  |    学号    |    班级    |
| :-----: | :----: | :--------: | :--------: |
| Java EE | 张宇晨 | 2020012249 | 软工2001班 |



[toc]

## 开发环境

Intellij IDEA 2020.2

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221015213903081.png" alt="image-20221015213903081" style="zoom:55%;" />



## 在线部署

项目已经部署在个人网站[登陆系统 (zhangyuchen.cn)](http://www.zhangyuchen.cn/P6/)中，欢迎老师访问评阅

![image-20221225194757385](E:\Pictures\Typora图片\image-20221225194757385.png)

**用户名：zyc     密码：123456**

（因为本项目的登陆验证是基于session实现的，如果浏览器禁用了Cookies，则本项目无法正常运行）



## 实习内容

### 1.  新建一个Spring MVC工程，练习Spring MVC控制器的编写、客户端参数的获取及显示。

具体SpringMVC控制器的编写在实习任务3.改写图书馆管理系统中已经完整展现，在此不再赘述。

![image-20221225182126522](E:\Pictures\Typora图片\image-20221225182126522.png)

### 2. 编写一个拦截器对所有的请求进行判断，若为登录用户则允许通过，若没有登录则转到登录页面。

拦截器的实现见任务3.改写图书管理系统

![image-20221225182008662](E:\Pictures\Typora图片\image-20221225182008662.png)

### 3. 改写图书管理系统

#### 登陆拦截

1. 登陆管理

   ![image-20221225185328069](E:\Pictures\Typora图片\image-20221225185328069.png)

   ![image-20221225185412062](E:\Pictures\Typora图片\image-20221225185412062.png)

   密码错误提示：

   ![image-20221225185444251](E:\Pictures\Typora图片\image-20221225185444251.png)

2. 请求拦截

3. ![image-20221225185827546](E:\Pictures\Typora图片\image-20221225185827546.png)

#### SpringMVC控制器

相关配置

<img src="E:\Pictures\Typora图片\image-20221225191055093.png" alt="image-20221225191055093" style="zoom:150%;" />

控制器

![image-20221225191413179](E:\Pictures\Typora图片\image-20221225191413179.png)

以登陆界面为例，action路径为/book/allBook

![image-20221225191513744](E:\Pictures\Typora图片\image-20221225191513744.png)

控制器调用业务类方法

![image-20221225191612134](E:\Pictures\Typora图片\image-20221225191612134.png)

调用方法SelectAllBook()

![image-20221225191805650](E:\Pictures\Typora图片\image-20221225191805650.png)

基于配置文件的SelectAllBook实现

![image-20221225191851231](E:\Pictures\Typora图片\image-20221225191851231.png)

属性绑定与页面跳转

![image-20221225192039214](E:\Pictures\Typora图片\image-20221225192039214.png)

![image-20221225192203225](E:\Pictures\Typora图片\image-20221225192203225.png)

结果

![image-20221225192253851](E:\Pictures\Typora图片\image-20221225192253851.png)

#### 图书表book

id自增，由数据库auto_increment方式实现（项目连接的是云端服务器的Mysql数据库）

![image-20221225180941703](E:\Pictures\Typora图片\image-20221225180941703.png)

初始数据填充

![image-20221225180911342](E:\Pictures\Typora图片\image-20221225180911342.png)

登陆界面-书籍列表

![image-20221225190112906](E:\Pictures\Typora图片\image-20221225190112906.png)

支持模糊查询

![image-20221225190056782](E:\Pictures\Typora图片\image-20221225190056782.png)

修改

![image-20221225190138556](E:\Pictures\Typora图片\image-20221225190138556.png)

新增

![image-20221225190155945](E:\Pictures\Typora图片\image-20221225190155945.png)



## 完整代码

完整代码在提交的作业压缩包中的p6文件夹中