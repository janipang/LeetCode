# not successfull

class Account:
    def __init__(self, account: str, pin: str, amount: int):
        self.account = account
        self.pin = pin
        self.amount = amount


class ATMService:
    def __init__(self):
        self.db_service = DBService()

    def deposit(self, account: str, amount: int):
        user_account = self.db_service.serve_account(account)
        user_account.amount += amount

    def withdraw(self, account: str, amount: int):
        user_account = self.db_service.serve_account(account)
        user_account.amount -= amount

    def transfer(self, src_account: str, dest_account: str, amount: int):
        user1_account = self.db_service.serve_account(src_account)
        user2_account = self.db_service.serve_account(dest_account)
        user1_account.amount -= amount
        user2_account.amount += amount

    def open_account(self, account: str, pin: str, amount: int = 0) -> Account | None:
        if self.db_service.check_exist_account(account) == True:
            return None
        new_account = Account(account, pin, amount)
        db_service.add_new_account(new_account)
        return new_account


class CashArchive:
    def __init__(self, thousand=0, fivehundred=0, hundred=0):
        self.total = (thousand * 1000) + (fivehundred * 500) + (hundred * 100)
        self.thousand = thousand
        self.fivehundred = fivehundred
        self.hundred = hundred

    def deposit_cash(self, amount, thousand, fivehundred, hundred) -> bool:
        if ((thousand * 1000) + (fivehundred * 500) + (hundred * 100)) != amount:
            return False
        self.total += amount
        self.thousand += thousand
        self.fivehundred += fivehundred
        self.hundred += hundred
        return True

    def withdraw_cash(self, amount) -> bool:
        if self.total < amount:
            return False
        use1000, use500, use100 = 0, 0, 0
        if amount >= 1000 and self.thousand > 0:
            use1000 = min(amount // 1000, self.thousand)
            amount -= use1000 * 1000
            self.thousand -= use1000
        if amount >= 500 and self.fivehundred > 0:
            use500 = min(amount // 500, self.fivehundred)
            amount -= use500 * 500
            self.fivehundred -= use500
        if amount >= 100 and self.hundred > 0:
            use100 = min(amount // 100, self.hundred)
            amount -= use100 * 100
            self.hundred -= use100
        payed_banknotes = [use1000, use500, use100]
        if amount == 0:
            return True
        else:
            self.thousand += use1000
            self.fivehundred += use500
            self.hundred += use100
            return False


class DBService:
    def __init__(self):
        self.accounts = []

    def verify_password(self, account: str, pin: str) -> bool:
        account_instance = self.serve_account(account)
        if pin == account_instance.pin:
            return True
        else:
            return False

    def check_exist_account(self, account: str) -> bool:
        for account_instance in self.accounts:
            if account_instance.account == account:
                return True
        return False

    def serve_account(self, account: str) -> Account | None:
        for account_instance in self.accounts:
            if account_instance.account == account:
                return account_instance
        return None

    def add_new_account(self, account: Account) -> bool:
        self.accounts.append(account)
        return True


# mode = ["deposit", "withdraw", "transfer", "open account"]
ATM = ATMService()
db_service = ATM.db_service
cash_archive = CashArchive(20, 20, 200)
while True:
    print(
        "\nSCB ATM Services\nplease select services that you prefer\n1) deposit\n2) withdraw\n3) transfer\n4) open account"
    )
    mode = input(">> ")
    if mode == "q":
        print("\tend of service.\nThank you for choosing SCB...")
        break

    if mode == "1":
        # get user_account:Account
        while True:
            user_account_number = input("your account number: ")
            if db_service.check_exist_account(user_account_number) == True:
                break
            else:
                print(
                    f"\taccount number {user_account_number} is incorrect, please try again"
                )
                continue

        for attempt in range(3):
            pin = input("account pin: ")
            if db_service.verify_password(user_account_number, pin) == True:
                user_account = db_service.serve_account(user_account_number)
                break
            elif (
                db_service.verify_password(user_account_number, pin) == False
                and attempt == 3 - 1
            ):
                print("\tyour attempt were rejected!")
            else:
                print("\tincorrect password, please try again...")
        if user_account is None:
            continue

        # get amount:int
        while True:
            try:
                amount = int(input("amount to deposit: "))
                if amount <= 0:
                    raise ValueError("amount must be positive.")
                break
            except:
                print("\tamount should be positive number")
                continue

        # get each banknotes
        while True:
            try:
                bank1000 = int(input("number of banknotes 1000: "))
                bank500 = int(input("number of banknotes 500: "))
                bank100 = int(input("number of banknotes 100: "))
                if bank1000 < 0 or bank500 < 0 or bank100 < 0:
                    raise ValueError("number of banknotes must be positive.")
                break
            except:
                print("\tnumber of banknotes should be positive number")
                continue

        # deposit
        if cash_archive.deposit_cash(amount, bank1000, bank500, bank100) == True:
            ATM.deposit(user_account_number, amount)
            print("---SUCCESSFULLY DEPOSIT---")
            print(f"account: {user_account.account},    balance: {user_account.amount}")
        else:
            print("\tDEPOSIT FAILED: please check amount and number of your banknotes")
            continue

    elif mode == "2":
        # get user_account:Account
        while True:
            user_account_number = input("your account number: ")
            if db_service.check_exist_account(user_account_number) == True:
                break
            else:
                print(
                    f"\taccount number {user_account_number} is incorrect, please try again"
                )
                continue

        for attempt in range(3):
            pin = input("account pin: ")
            if db_service.verify_password(user_account_number, pin) == True:
                user_account = db_service.serve_account(user_account_number)
                break
            elif (
                db_service.verify_password(user_account_number, pin) == False
                and attempt == 3 - 1
            ):
                print("\tyour attempt were rejected!")
            else:
                print("\tincorrect password, please try again...")
        if user_account is None:
            continue

        # get amount
        while True:
            try:
                amount = int(input("amount to withdraw: "))
                if amount <= 0:
                    raise ValueError("Number must be positive.")
                if amount > user_account.amount:
                    print(
                        f"\tATTEMPT FAILED: amount valid {user_account.amount} B.- is not enough"
                    )
                    continue
                break
            except:
                print("\tamount should be positive number")
                continue

        # withdraw
        if cash_archive.withdraw_cash(amount) == True:
            ATM.withdraw(user_account_number, amount)
            print("---SUCCESSFULLY WITHDRAW---")
            print(f"account: {user_account.account},    balance: {user_account.amount}")

    elif mode == "3":
        # get user_account:Account
        while True:
            user_account_number = input("your account number: ")
            if db_service.check_exist_account(user_account_number) == True:
                break
            else:
                print(
                    f"\taccount number {user_account_number} is incorrect, please try again"
                )
                continue

        for attempt in range(3):
            pin = input("account pin: ")
            if db_service.verify_password(user_account_number, pin) == True:
                user_account = db_service.serve_account(user_account_number)
                break
            elif (
                db_service.verify_password(user_account_number, pin) == False
                and attempt == 3 - 1
            ):
                print("\tyour attempt were rejected!")
            else:
                print("\tincorrect password, please try again...")
                
        # get target_account:Account
        while True:
            target_account_number = input("target account number: ")
            if db_service.check_exist_account(target_account_number) == True:
                break
            else:
                print(
                    f"\taccount number {target_account_number} is incorrect, please try again"
                )
                continue

        # get amount:int
        while True:
            try:
                amount = int(input("amount to deposit: "))
                if amount <= 0:
                    raise ValueError("amount must be positive.")
                if amount > user_account.amount:
                    print(f"\tATTEMPT FAILED: amount valid {user_account.amount} B.- is not enough")
                    continue
                break
            except (ValueError):
                print("\tamount should be positive number")
                continue
        
        # transfer
        ATM.transfer(user_account_number, target_account_number, amount)
        print("---SUCCESSFULLY WITHDRAW---")
        print(f"account: {user_account.account},    balance: {user_account.amount}")
                
    elif mode == "4":
        while True:
            user_account_number = input("select your account number (8 digit): ")
            if len(user_account_number) != 8:
                print("account number should have 8 digit")
                continue
            elif db_service.check_exist_account(user_account_number) == False:
                pin = input("account pin: ")
                ATM.open_account(user_account_number, pin)
                print("--- OPEN ACCOUNT SUCCESSFULLY ---")
                break
            else:
                print(
                    "\tthe number has used already, please try again with another number"
                )
                continue
    else:
        print("\tservice no valid, please try again\n")