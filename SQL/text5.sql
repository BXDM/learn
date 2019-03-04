create table class
(
    code varchar(20) primary key,
    name varchar(20) not null
);
create table ceshi
(
    ids int auto_increment primary key,
    uid varchar(20),
    name varchar(20),
    class varchar(20),
    foreign key (class)  references class(code) 
);