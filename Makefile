all:
	@cd include && make
	@cd server && make
	@cd client && make

.PHONY:client
client:
	@cd include && make 
	@cd client && make

.PHONY:server
server:
	@make -C include
	@make -C server

.PHONY:clean
clean:
	@make -C include clean
	@make -C server clean
	@make -C client clean
