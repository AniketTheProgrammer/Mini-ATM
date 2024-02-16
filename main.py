MAX_ACCOUNTS = 10

# Class to represent an account
class Account:
    def __init__(self, accountNumber, pin, balance):
        self.accountNumber = accountNumber
        self.pin = pin
        self.balance = balance

accounts = []
accountCount = 0

# Function to create a new account
def createAccount(accountNumber, pin, initialBalance):
    global accountCount
    if accountCount < MAX_ACCOUNTS:
        accounts.append(Account(accountNumber, pin, initialBalance))
        accountCount += 1
        print("Account created successfully!")
    else:
        print("Cannot create more accounts. Limit reached.")

# Function to find an account by account number
def findAccount(accountNumber):
    for i, account in enumerate(accounts):
        if account.accountNumber == accountNumber:
            return i  # Return the index of the account if found
    return -1  # Return -1 if account not found

# Function to simulate a withdrawal
def withdraw(accountIndex, amount):
    if accounts[accountIndex].balance >= amount:
        accounts[accountIndex].balance -= amount
        print(f"Withdrawal successful. Remaining balance: ${accounts[accountIndex].balance:.2f}")
    else:
        print("Insufficient funds!")

# Function to simulate a deposit
def deposit(accountIndex, amount):
    accounts[accountIndex].balance += amount
    print(f"Deposit successful. New balance: ${accounts[accountIndex].balance:.2f}")

# Function to display account balance
def displayBalance(accountIndex):
    print(f"Account Number: {accounts[accountIndex].accountNumber}")
    print(f"Current Balance: ${accounts[accountIndex].balance:.2f}")

# Creating a sample account
print("Enter Account Number:")
acc_no = int(input())
print("Enter Account Pin:")
acc_pin = input()
print("Enter Account Starting Balance:")
init_balance = float(input())
createAccount(acc_no, acc_pin, init_balance)

choice = 0
while choice != 2:
    print("\nWelcome to Mini ATM")
    print("1. Login")
    print("2. Exit")
    choice = int(input("Enter choice: "))

    if choice == 1:
        print("Enter account number: ")
        accountNumber = int(input())
        print("Enter PIN: ")
        pin = input()

        accountIndex = findAccount(accountNumber)
        if accountIndex != -1 and accounts[accountIndex].pin == pin:
            option = 0
            while option != 4:
                print("\n1. Withdraw")
                print("2. Deposit")
                print("3. Check Balance")
                print("4. Logout")
                option = int(input("Enter option: "))

                if option == 1:
                    amount = float(input("Enter amount to withdraw: "))
                    withdraw(accountIndex, amount)
                elif option == 2:
                    amount = float(input("Enter amount to deposit: "))
                    deposit(accountIndex, amount)
                elif option == 3:
                    displayBalance(accountIndex)
                elif option == 4:
                    print("Logged out.")
                else:
                    print("Invalid option")
        else:
            print("Invalid account number or PIN")
    elif choice == 2:
        print("Exiting...")
    else:
        print("Invalid choice")
