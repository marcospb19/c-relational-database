echo "Initializing memory leak check" && \
valgrind --leak-check=full --log-file="log/valgrindLog.txt" ../sgbd && \
echo Log created at 'valgrind/valgrindLog.txt'
