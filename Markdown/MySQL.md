## MySQL

[TOC]



#### 一、基本操作 

##### 1、登录本地MySQL

`mysql -u [用户名] -p[密码]`

> 用户名默认为	root
>
> -p 后面紧跟 密码

`mysql -h 127.0.0.1 -p 3306 -u root -p[密码]`

`mysql -h localhost -p 3306 -u root -p[密码]`

-h	后面跟服务器或主机的主机名或IP地址

-p	端口号，默认为 3306，可以省略

-u	账户名

-p	 **紧跟** `密码`

正确的登录方式：

```
mysql -u root -p
```

然后输入密码

##### 2、基本命令

语句以	 `;` 结尾

**status**		查看状态信息

**use [database_name]**		切换数据库

```sql
show databases		#查看表结构
```



#### 二、数据库操作

##### 1、创建数据库

```mysql
create database name
```

##### 2、创建表格

```sql
create table products（
	A_id char(3),
	B_id char(5),
	description char(20),
	price,
	mount
	);
```

表记录的更新操作
插入日期  2019-3-29

