import pandas
import numpy as np
import  matplotlib
import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import StandardScaler
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn import linear_model
from sklearn.model_selection import train_test_split
from sklearn import linear_model


#Step 1 Analysis
data = pandas.read_csv("loan_old.csv")


has_missing = data.isnull().sum().sum()>0
if has_missing: print("The Data Has Missing values")
else: print("The data does not contain any missing values")

for j in range(data.shape[1]):
        print( data.columns[j]," ",data.iloc[:,j].isnull().sum())


print("-------------------------------------------\n")
column_types = data.dtypes
# Print the data types
print(column_types)

print("-------------------------------------------\n")

#Describe numeric data
pd.set_option('display.max_columns',None)
print("------------\n")
numeric = data.select_dtypes(include=['int64','float64'])
feature_stats = numeric.describe()
print(feature_stats)


print("-------------------------------------------\n")




print("------------\n")
numeric = data.select_dtypes(include=['int64','float64'])
sns.pairplot(numeric)
plt.show()




#Step 2 Preprocessing

#removing missing values
pd.set_option('display.max_columns',None)

data = data.dropna()
print(data)
#separate features and targets

x=  data.drop(columns=["Loan_ID","Max_Loan_Amount","Loan_Status"])
y1 = data['Max_Loan_Amount']
y2 = data['Loan_Status']
#shuffle data and split into training and test sets
x_train, x_test, y1_train, y1_test,y2_train,y2_test = train_test_split(x, y1,y2, test_size=0.3, random_state=100)


x_train = x_train.to_numpy()

y1_train = y1_train.to_numpy()
y2_train = y2_train.to_numpy()
x_test = x_test.to_numpy()
y1_test = y1_test.to_numpy()
y2_test = y2_test.to_numpy()



#Encoding data
xdata_encdoers = []
ydata_encoders = []
#Encode X_train Categorical  columns
for j in range(x_train.shape[1]):
        if(column_types.iloc[j+1]!= object ):
                continue
        le = LabelEncoder()
        le.fit(x_train[:,j])
        xdata_encdoers.append(le)
        x_train[:,j]= le.transform(x_train[:,j])


#Encode X_test Categorical Columns using x_training Encoders
index = 0
for j in range(x_test.shape[1]):
        if(column_types.iloc[j+1]!= object):
                continue
        le = xdata_encdoers[index]
        x_test[:,j]= le.transform(x_test[:,j])
        index += 1

#Encode  Loan Status column in training set
le = LabelEncoder()
le.fit(y2_train)
ydata_encoders.append(le)
y2_train = le.transform(y2_train)

#Encode  Loan Status column in test  set
le = ydata_encoders[0]

y2_test = le.transform(y2_test)

print("-------------------------------------------\nX_Traing After Encoding")
print(x_train)


print("Loan Status After Encoding")
print(y2_train)


print("-------------------------------------------\n")


# #decoding

#Standerdizing the Training and testing

for j in range(x_train.shape[1]-2):
        if(column_types.iloc[j+1]== object ):
                continue
        mean = np.mean(x_train[:,j])
        std = np.std(x_train[:,j])
        x_train[:,j]= (x_train[:,j]-mean)/std

        mean = np.mean(x_test[:, j])
        std = np.std(x_test[:, j])
        x_test[:, j] = (x_test[:, j] - mean) / std


print("X_train After Standerdization\n",x_train)

print("-------------------------------------------\n")

#3- linear Regression

Linearmodel = linear_model.LinearRegression()
Linearmodel.fit(x_train, y1_train)



print('Coefficients Of Linear Regression : \n', Linearmodel.coef_, " ", Linearmodel.intercept_)
print('Correct predicitions ratio Of Linear Regression Model: %.2f'% Linearmodel.score(x_test, y1_test))

print("----------------------------------------------\nLogistic Regression\n-----------")
#4- Logistic Regression

class Logistic_Regression:
    thetas = []


    def fit(self,x,y):

         x = np.insert(x,0,np.ones(x.shape[0]),axis=1)

         self.thetas = np.ones(x.shape[1])

         alpha = 0.3
         max_iterations = 2000
         m = x.shape[0]
         for i in range(max_iterations):
             z = np.dot(x, self.thetas).astype('float')

             h = 1 / (1 + np.exp(-z))
            # print(self.cost_function(y,h))
             for j in range(self.thetas.shape[0]):
                par_der=(1/m)*sum((h-y)*x[:,j] )
                self.thetas[j] =self.thetas[j] -alpha*par_der

    def compute_cost(self, y_true, y_pred):
        m = len(y_true)
        epsilon = 1e-15
        # Adding a small constant to avoid log(0) and log(1) instability
        y_pred = np.clip(y_pred, epsilon, 1 - epsilon)
        # Formula: J(w, b) = - (1 / m) * Σ [y * log(a) + (1 - y) * log(1 - a)]
        cost = - (1 / m) * np.sum(y_true * np.log(y_pred) + (1 - y_true) * np.log(1 - y_pred))
        return cost

    def score(self,x_test, y_true):
        y_pred = self.predict(x_test)
        correct_predictions = np.sum(y_pred == y_true)
        # Calculate accuracy
        total_examples = len(y_true)
        accuracy = correct_predictions / total_examples
        return accuracy*100
    def predict(self,x):
        x = np.insert(x, 0, np.ones(x.shape[0]), axis=1)

        z = np.dot(x, self.thetas).astype('float')

        h = 1 / (1 + np.exp(-z))
        h[h<0.5]=0
        h[h>0.5]=1
        return h.astype('int')

Logmodel = Logistic_Regression()

Logmodel.fit(x_train, y2_train)
print('Accuracy of Logistic Regression model: %.2f'% Logmodel.score(x_test, y2_test),"%")
print("Thetas Of logistic Model: ",Logmodel.thetas)
################################################################################################################
#NewData

data = pandas.read_csv("loan_new.csv")


#Step 2 Preprocessing

#removing missing values

data = data.dropna()


x_new=  data.drop(columns=["Loan_ID"]).to_numpy()

#Encoding data
#Encode New Categorical Columns using x_training Encoders
index = 0
for j in range(x_new.shape[1]):
        if(column_types.iloc[j+1]!= object):
                continue
        le = xdata_encdoers[index]
        x_new[:,j]= le.transform(x_new[:,j])
        index += 1

#Standerdizing the Training and testing

for j in range(x_new.shape[1]-2):
        if(column_types.iloc[j+1]== object ):
                continue
        mean = np.mean(x_new[:,j])
        std = np.std(x_new[:,j])
        x_new[:,j]= (x_new[:,j]-mean)/std
print("-------------------------------------------\n")

print("New Data After Being Preprocessed ")

print(x_new)
print("-------------------------------------------\n")
print("Max Loan Predictions of New Data:")
y1_pred = Linearmodel.predict(x_new)


y2_pred = Logmodel.predict(x_new)


print(y1_pred)
le = ydata_encoders[0]
y2_pred = le.inverse_transform(y2_pred)
print("Predicted Loan Status of New Data: ")
print(y2_pred)

