<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>首页</title>
    <style>
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }
        body{
            background: #ffffcc;
        }
    </style>
</head>
<body>
<div style="
    position: absolute;
    left: 50%;top: 50%;
    transform: translate(-50%,-50%); text-align: center;">
    <h2 class="colortxt">欢迎来到学生信息管理系统</h2>
    <br>
    <h3 class="colortxt">本系统的控制器是由过滤器实现的</h3>
    <br>
    <h3><a href="list.jsp?action=list" >点此查看所有学生列表</a></h3><br>
    <%--<h3><a href="StudentListPageServlet?currentPage=1">分页显示所有学生</a></h3>--%>
</div>
</body>
</html>
