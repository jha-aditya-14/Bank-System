# importing modules

import pickle
import os
import pathlib

# ============== Main Start ===========================

class Account :  # Building a class Account
    accNo = 0    # initialize Account Number to 0
    name = ''    # initialize Name to Empty String
    deposit=0    # initialize deposit to 0
    type = ''    # initialize type to Empty String
    
    def createAccount(self):   # Function to create account
    	# ========= Taking all neccesary inputs ================

        self.accNo= int(input("Enter the account no : "))
        self.name = input("Enter the account holder name : ")
        self.type = input("Ente the type of account [C/S] : ")
        self.deposit = int(input("Enter The Initial amount(>=500 for Saving and >=1000 for current"))
        print("\n\n\nAccount Created")
    
    def showAccount(self): # Function to show account details   
        print("Account Number : ",self.accNo)
        print("Account Holder Name : ", self.name)
        print("Type of Account",self.type)
        print("Balance : ",self.deposit)
    
    def modifyAccount(self):
        print("Account Number : ",self.accNo)
        self.name = input("Modify Account Holder Name :")
        self.type = input("Modify type of Account :")
        self.deposit = int(input("Modify Balance :"))
        
    def depositAmount(self,amount): # Function to show deposite amount details
        self.deposit += amount
    
    def withdrawAmount(self,amount):  # Function to show deposite amount details
        self.deposit -= amount
    
    def report(self):  # Function to show deposit amount details
        print(self.accNo, " ",self.name ," ",self.type," ", self.deposit)
    
    def getAccountNo(self):   # Function to show Account Number details
        return self.accNo
    def getAcccountHolderName(self):   # Function to show AcccountHolderName
        return self.name
    def getAccountType(self):  # Function to show scc. type details
        return self.type
    def getDeposit(self):   # Function to getdeposit details
        return self.deposit
    
# ================= Outer Fuction from the Class ==============================


# ===================== Main Intro Page ===================================
def intro():
    print("\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$")
    print("\t\t\t\tBANK MANAGEMENT SYSTEM")
    print("\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$")

    input()  # normal input to pause and contiue when press Enter



def writeAccount():        # For new accont writing data
    account = Account()
    account.createAccount()
    writeAccountsFile(account)   # Write acc file call with account number

def displayAll():               # Opens the file displays all details if file not empty then only it can show else show "no record"
    file = pathlib.Path("accounts.data")
    if file.exists ():                       
        infile = open('accounts.data','rb')
        mylist = pickle.load(infile)
        for item in mylist :
            print(item.accNo," ", item.name, " ",item.type, " ",item.deposit )
        infile.close()
    else :
        print("No records to display")
        

def displaySp(num):            # similar to above func but the difference if that is show only the acc details which we want to see functioning is similar to above
    file = pathlib.Path("accounts.data") 
    if file.exists ():
        infile = open('accounts.data','rb')
        mylist = pickle.load(infile)
        infile.close()
        found = False
        for item in mylist : # geting value in mylist to item one by one 
            if item.accNo == num :         # if acc no. match then only it show details
                print("Your account Balance is = ",item.deposit)
                found = True
    else :
        print("No records to Search")
    if not found :
        print("No existing record with this number")

def depositAndWithdraw(num1,num2):   # Deposit and Withdraw functionality
    file = pathlib.Path("accounts.data")  # opening file path
    if file.exists ():   # Checking Existance
        infile = open('accounts.data','rb')     # open file 
        mylist = pickle.load(infile) # load and give its data to mylist
        infile.close()
        os.remove('accounts.data') # and now removed the file
        for item in mylist :  # getting 1 by one item from mylist
            if item.accNo == num1 :  # value which passed  checking from it num1 is acc No
                if num2 == 1 :       # num2 for checking that we want to deposit or withdraw if num2=1 we deposite elif num2 =2 we will withdraw
                    amount = int(input("Enter the amount to deposit : "))
                    item.deposit += amount  # As we deposit so amount add to existing acc
                    print("Your account is updted")
                elif num2 == 2 :
                    amount = int(input("Enter the amount to withdraw : "))
                    if amount <= item.deposit :
                        item.deposit -=amount  # As we withdraw so we should detuct amt from current amt in acc
                    else :
                        print("You cannot withdraw larger amount")
                
    else :
        print("No records to Search")
    outfile = open('newaccounts.data','wb')  # Open a newfile in read  mode
    pickle.dump(mylist, outfile) # dumping data mylist to outfile
    outfile.close() 
    os.rename('newaccounts.data', 'accounts.data') # now we renamed it as  our old file name
     
def deleteAccount(num):  # Use to delete it take acc. no if that exist then it will delete and upade file using pickle (load and dump)
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        oldlist = pickle.load(infile)
        infile.close()
        newlist = []
        for item in oldlist :
            if item.accNo != num :
                newlist.append(item)
        os.remove('accounts.data')
        outfile = open('newaccounts.data','wb')
        pickle.dump(newlist, outfile)
        outfile.close()
        os.rename('newaccounts.data', 'accounts.data')
     
def modifyAccount(num):  # Similar as delete but instead of deleate we are updating our data by taking input  and write data on temp and dump it
    file = pathlib.Path("accounts.data")
    if file.exists ():
        infile = open('accounts.data','rb')
        oldlist = pickle.load(infile)
        infile.close()
        os.remove('accounts.data')
        for item in oldlist :
            if item.accNo == num :
                item.name = input("Enter the account holder name : ")
                item.type = input("Enter the account Type : ")
                item.deposit = int(input("Enter the Amount : "))
        
        outfile = open('newaccounts.data','wb')
        pickle.dump(oldlist, outfile)
        outfile.close()
        os.rename('newaccounts.data', 'accounts.data')
   

def writeAccountsFile(account) : 
    
    file = pathlib.Path("accounts.data") # open a file path
    if file.exists ():  # if the path file exist it will run this condition
        infile = open('accounts.data','rb')  # open acc file in read mode (read binary mode)
        oldlist = pickle.load(infile)  # load the file in binary mode
        oldlist.append(account)  # Append account to oldlist 
        infile.close() 
        os.remove('accounts.data') # removed accounts file
    else :
        oldlist = [account] 
    outfile = open('newaccounts.data','wb') # open file in write mode
    pickle.dump(oldlist, outfile) #Dumping data of file oldlist to outfile
    outfile.close() 
    os.rename('newaccounts.data', 'accounts.data') # Rnamed the newaccount back to accounts
    
        
# ************************************** starting of the program **************************************
ch=''    # Initialize ch to empty string which required on choice
num=0    # Initialize num 0
intro()  # Calling Introfunction First Then Options to Choose

while ch != 8:  # Choice 
    
    print("\tMAIN MENU")
    print("\t1. NEW ACCOUNT")
    print("\t2. DEPOSIT AMOUNT")
    print("\t3. WITHDRAW AMOUNT")
    print("\t4. BALANCE ENQUIRY")
    print("\t5. ALL ACCOUNT HOLDER LIST")
    print("\t6. CLOSE AN ACCOUNT")
    print("\t7. MODIFY AN ACCOUNT")
    print("\t8. EXIT")
    print("\tSelect Your Option:  ")
    ch = input()
    
    
    if ch == '1':
        writeAccount() # choice 1 Calling  New Account Function to build
    elif ch =='2':
        num = int(input("\tEnter The account No. : "))
        depositAndWithdraw(num, 1)     # As in Deposit and withdraw both on same funtion using choice so when we chose deposite  we set the num to 1 that passed into function due to which deposit condition will run
    elif ch == '3':
        num = int(input("\tEnter The account No. : "))
        depositAndWithdraw(num, 2)     # As in Deposit and withdraw both on same funtion using choice so when we chose withdraw  we set the num to 2 that passed into function due to which withdraw condition will run
    elif ch == '4':
        num = int(input("\tEnter The account No. : "))  # To check Balance inquiry we take input of acc no then we call the function display by passing num into it that is acc. no
        displaySp(num)
    elif ch == '5':
        displayAll();    # Display All Acc. Details Present on Data
    elif ch == '6':
        num =int(input("\tEnter The account No. : ")) # To Delete we take input of acc no then we call the function delete by passing num into it that is acc. no that indicate we have to delete this account number
        deleteAccount(num)
    elif ch == '7':
        num = int(input("\tEnter The account No. : ")) # To check Acc. No that to be modify we take input of acc no then we call the function modifyAccount by passing num into it that is acc. no
        modifyAccount(num)
    elif ch == '8': # Exit from the Program
        print("\tThanks for using bank managemnt system")
        break 
    else :
        print("Invalid choice") 
    
    ch = input("Enter your choice : ") # If Invaild Choice U can re-enter choice 
    


    
    
    
    
    
    
    
    
    
