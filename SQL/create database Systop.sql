create database Systop
on  primary
(  /*以下是主数据文件的属性*/
   name=‘Systop', --主数据文件的逻辑名称
   filename=‘E:\Systop\DB\Systop.mdf',--主数据文件的物理路径
   size=3mb, --主数据文件的初始大小
   maxsize=unlimited, --主数据文件的最大值
   filegrowth=10%  --主数据文件的增长率
)
log on
(  /*以下是日志文件的属性*/
   name=‘Systop_log', --日志文件的逻辑名称
   filename= ‘E:\Systop\DB\Systop_log.ldf',  --日志文件的物理路径
   size=1mb,  --日志文件的初始大小
   filegrowth=10%  --日志文件的增长率
)
go
