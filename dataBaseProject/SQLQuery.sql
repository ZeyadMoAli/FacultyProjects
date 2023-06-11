/*==============================================================*/
/* Table: Client                                                */
/*==============================================================*/
create table Client 
(
   C_ID                 integer        IDENTITY        not null,
   FName                varchar(15)                    not null,
   LName                varchar(15)                    not null,
   Email                varchar(25)    UNIQUE          not null,
   Password             varchar(15)                    not null,
   Phone                varchar(11)                    not null,
   Age                  integer                        null,
   Gender               varchar(6)                     null,
   City                 varchar(15)                    not null,
   Street               varchar(15)                    not null,
   constraint PK_CLIENT primary key clustered (C_ID)
);

/*==============================================================*/
/* Table: Game                                                  */
/*==============================================================*/
create table Game 
(
   G_ID                 integer       IDENTITY         not null,
   V_ID                 varchar(8)                     not null,
   Name                 varchar(15)                    not null,
   Category             varchar(10)                    not null,
   "Release"            date                           not null,
   Price                integer                        not null,
   Quantity             integer                        not null,
   constraint PK_GAME primary key clustered (G_ID, V_ID)
);

/*==============================================================*/
/* Table: Rents                                                 */
/*==============================================================*/
create table Rents 
(
   Rental_ID            integer       IDENTITY         not null,
   C_ID                 integer                        not null,
   G_ID                 integer                        not null,
   V_ID                 varchar(8)                     null,
   Rent_date            date                           not null,
   Return_date          date                           null,
   constraint PK_RENTS primary key clustered (Rental_ID, C_ID, G_ID)
);

/*==============================================================*/
/* Table: Vendor                                                */
/*==============================================================*/
create table Vendor 
(
   V_ID                 varchar(8)                     not null,
   Name                 varchar(15)                    not null,
   Email                varchar(25)                    not null,
   Corporate            varchar(15)                    null,
   constraint PK_VENDOR primary key clustered (V_ID)
);

/*==============================================================*/
/* Table: Admin                                                */
/*==============================================================*/

create table Admin
(
    Id         INT         NOT NULL PRIMARY KEY IDENTITY, 
    [Username] VARCHAR(15) NULL, 
    [Password] VARCHAR(15) NULL
)




alter table Game
   add constraint FK_GAME_REFERENCE_VENDOR foreign key (V_ID)
      references Vendor (V_ID)
      on update cascade
      on delete cascade;

alter table Rents
   add constraint FK_RENTS_REFERENCE_CLIENT foreign key (C_ID)
      references Client (C_ID)
      on update cascade
      on delete cascade;

alter table Rents
   add constraint FK_RENTS_REFERENCE_GAME foreign key (G_ID, V_ID)
      references Game (G_ID, V_ID)
      on update cascade
      on delete cascade;

	  

	  INSERT INTO Admin
	  VALUES ('Admin', '1234')



	  INSERT INTO Client
	  VALUES ('Zeyad', 'Mohamed', 'zeyad@gmail.com', '1234' ,'0111020000' , '21', 'Male', 'Cairo', 'street1234' )

	  INSERT INTO Client
	  VALUES ('Mohamed', 'Ahmed', 'Mohamed@gmail.com', '12345' ,'011102005' , '21', 'Male', 'Cairo', 'street1235' )

	  INSERT INTO Client
	  VALUES ('yossef', 'Ali', 'yossef@gmail.com', '12346' ,'011102006' , '21', 'Male', 'Cairo', 'street1236' )

	  INSERT INTO Client
	  VALUES ('Essra', 'Mahmoud', 'Essra@gmail.com', '12347' ,'011102007' , '21', 'Female', 'Cairo', 'street1237' )

	  INSERT INTO Client
	  VALUES ('Rana', 'Salam', 'Rana@gmail.com', '123478' ,'0111020078' , '21', 'Female', 'Cairo', 'street1238')



	  INSERT INTO Vendor
	  VALUES ('1','Islam', 'valorant@gmail.com', 'riot')
	  
	  INSERT INTO Vendor
	  VALUES ('2','Ali', 'ALi@gmail.com', 'Activation')
	  
	  INSERT INTO Vendor
	  VALUES ('3','Kero', 'Kero@gmail.com', 'RockStar')

	  INSERT INTO Vendor
	  VALUES ('4','Amgad', 'amgad@gmail.com', 'Nintendo')

	  INSERT INTO Vendor
	  VALUES ('5','Mirna', 'Mirna@gmail.com', 'Epic Games')

	  INSERT INTO Vendor
	  VALUES ('6','Ahmed', 'Ahmed@gmail.com', 'Krafton')



	  INSERT INTO Game
	  VALUES ('1', 'Valorant' , 'Action', '2020-1-25','30', '37')
	  
	  INSERT INTO Game
	  VALUES ('2', 'Call Of Duty' , 'War', '2009-1-25','700', '22')
	  
	  INSERT INTO Game
	  VALUES ('3', 'GTA' , 'Action', '2005-10-25','150', '13')

	  INSERT INTO Game
	  VALUES ('6', 'PUBG' , 'War', '2005-10-25','175', '20')



	  INSERT INTO Rents
	  VALUES ('1', '5' ,'6','2022-4-25', '2022-4-30' )

	  INSERT INTO Rents
	  VALUES ('2', '1', '1', '2022-4-25', '2022-4-30' )

	  INSERT INTO Rents
	  VALUES ('3', '3', '3', '2022-4-25', '2022-4-30' )

	  INSERT INTO Rents
	  VALUES ('3', '2', '2', '2022-4-25', '2022-4-30' )

	  INSERT INTO Rents
	  VALUES ('4', '5', '6', '2022-4-25', '2022-4-30' )

	  INSERT INTO Rents
	  VALUES ('5', '2', '2', '2022-5-25', '2022-5-30' )

	  INSERT INTO Rents
	  VALUES ('2', '1', '1', '2022-4-27', '2022-4-30' )

	  INSERT INTO Rents
	  VALUES ('5', '3', '3', '2022-4-1', '2022-4-5' )


/*==============================================================*/
/*                         QUERIES                              */
/*==============================================================*/

/* A) Game with maximum number of renters*/
	  select  top 1  G_ID,count(G_ID) as TotalRents
	  from Rents 
	  Group By G_ID 
	  Order By TotalRents DESC


/* B) Games that hadn't any renters last month*/
	  select G_ID  from Game
	  except
	  (
	  
	  select   G_ID 
	  from Rents 
	  WHERE DATEDIFF(MONTH,Rent_date, GETDATE())=1
	  Group By G_ID
	  
	  )
	  union all ( 
	  select   G_ID 
	  from Rents 
	  WHERE DATEDIFF(MONTH,Rent_date, GETDATE())=1
	  Group By G_ID 
	  EXCEPT
	  SELECT G_ID  FROM Game
	  )
	  

/* C) Client with max renting last month*/
	  select  top 1  C_ID,count(C_ID) as TotalRents
	  from Rents 
	  where DATEDIFF(MONTH,Rent_date, GETDATE())=1
	  Group By C_ID 
	  Order By TotalRents DESC

	  
/* D) Vendor with max renting out last month*/

	  select  top 1  V_ID,count(V_ID) as TotalRents
	  from Rents 
	  where DATEDIFF(MONTH,Rent_date, GETDATE())=1
	  Group By V_ID 
	  Order By TotalRents DESC

/* E) Vendors whose games haden't any renters last month*/

	  select V_ID  from Vendor
	  except
	  (
	  select   V_ID 
	  from Rents 
	  WHERE DATEDIFF(MONTH,Rent_date, GETDATE())=1
	  Group By V_ID
	  )
	  union all ( 
	  select   V_ID 
	  from Rents 
	  WHERE DATEDIFF(MONTH,Rent_date, GETDATE())=1
	  Group By V_ID 
	  EXCEPT
	  SELECT V_ID  FROM Game
	  )

	  	
/* F) Vendors who didn't add any games last year*/
	select V_ID  from Vendor
	  except
	  (
	select   V_ID 
	  from Game 
	  WHERE Release >DATEADD(YEAR,-1, GETDATE())
	  Group By V_ID
	  )
	  union all ( 
	select   V_ID 
	  from Game 
	  WHERE Release >DATEADD(YEAR,-1, GETDATE())
	  Group By V_ID
	  EXCEPT
	  SELECT V_ID  FROM Game
	  )
	  




