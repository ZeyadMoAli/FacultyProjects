we used spring initializer for this project

spring boot version-> 3.0.1

java version-> java 17

to run the project on eclipse-> open eclipse and import our project on it

there is a Postman collection in the submetion file you can import it and ues it

----------------------------------------------------------------------------------------------------------------------------------------------------------------


every Customer has 1000 pound in his credit card and 1000 pound in his wallet by default

----------------------------------------------------------------------------------------------------------------------------------------------------------------

the system has default customer with this data:

{
    "username": "zeyad",
    "email":"gmail",
    "password":"123"
    
} 

----------------------------------------------------------------------------------------------------------------------------------------------------------------

when makeing any customer request (ex: singin, signup, checkServiceDiscount, checkServiceDiscount, AddToWalletRefundRequest, SearchService)
you need to give customer as a jason boody on the request, example:

{
    "username": "ali",
    "email":"hotmail",
    "password":"456"
    
} 
