Clear-Host

Write-Host "Cleaning project..."
make clean
Write-Host ""

Write-Host "Building project..."
make
Write-Host ""
