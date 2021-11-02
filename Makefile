all:
	cd server && make
	cd client && make

# server:
#     cd server && make

# client:
#     cd client && make

clean:
	cd server && make clean
	cd client && make clean
