# Introduction






# Hotel Data Exchange Protocal / HDEP


##### Frame : Book a room as a registered customer

Request frame: Frame_ID + Client_ID + Date + Room_Number + Payment(optional)

Response frame: Frame_ID + Client_ID + Booking_Status + Booking_ID


#### Frame: Cancel Booking as a registered customer

Request frame: Frame_ID + Client_ID + Booking_ID

Response frame: Frame_ID + Client_ID + Cancel_Booking_Status


##### Frame : Book a room as an unregistered customer

Request frame: Frame_ID + Date + Room_Number + Payment(mandatory)

Response frame: Frame_ID + Booking_Status + Booking_ID


#### Frame: Cancel Booking as an unregistered customer

Request frame: Frame_ID + Booking_ID

Response frame: Frame_ID + Cancel_Booking_Status


##### Frame : Register an account as a new user

Request frame: Frame_ID + Name + Password + Default_Payment

Response frame: Frame_ID + Client_ID + Register_Status


#### Frame : Modify password

Request frame: Frame_ID + Old_Password + New_Password

Response frame: Frame_ID + Modification_Status


#### Frame: Delete account

Request frame: Frame_ID + Client_ID + Password

Response frame: Frame_ID + Client_ID + Modification_Status


#### Frame: Login

Request frame: Frame_ID + Name + Password

Response frame: Frame_ID + Login_Status


#### Frame: Logout

Request frame: Frame_ID

Response frame: Frame_ID + Logout_Status


