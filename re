local Players = game:GetService("Players")
local player = Players.LocalPlayer
local gui = Instance.new("ScreenGui")
gui.Name = "AccessPanel"
gui.ResetOnSpawn = false
gui.Parent = player:WaitForChild("PlayerGui")

local Main = Instance.new("Frame")
Main.Size = UDim2.fromScale(.45,.75)
Main.Position = UDim2.fromScale(.5,.5)
Main.AnchorPoint = Vector2.new(.5,.5)
Main.BackgroundColor3 = Color3.fromRGB(10,10,10)
Main.Parent = gui

Instance.new("UICorner", Main).CornerRadius = UDim.new(0,15)

local Scroll = Instance.new("ScrollingFrame")
Scroll.Size = UDim2.fromScale(1,1)
Scroll.BackgroundTransparency = 1
Scroll.BorderSizePixel = 0
Scroll.ScrollBarThickness = 8
Scroll.Parent = Main

local Layout = Instance.new("UIListLayout")
Layout.Padding = UDim.new(0,15)
Layout.HorizontalAlignment = Enum.HorizontalAlignment.Center
Layout.Parent = Scroll

--------------------------------------------------
-- ACCESS PANEL
--------------------------------------------------

local AccessPanel = Instance.new("Frame")
AccessPanel.Size = UDim2.new(1,-20,0,350)
AccessPanel.BackgroundColor3 = Color3.fromRGB(15,15,15)
AccessPanel.Parent = Scroll

Instance.new("UICorner", AccessPanel).CornerRadius = UDim.new(0,15)

local Title = Instance.new("TextLabel")
Title.Size = UDim2.new(1,0,0,60)
Title.BackgroundTransparency = 1
Title.Text = "ACCESS PANEL"
Title.TextScaled = true
Title.TextColor3 = Color3.new(1,1,1)
Title.Font = Enum.Font.GothamBold
Title.Parent = AccessPanel

local Info = Instance.new("TextLabel")
Info.Position = UDim2.new(0,20,0,80)
Info.Size = UDim2.new(1,-40,0,120)
Info.BackgroundTransparency = 1
Info.TextXAlignment = Enum.TextXAlignment.Left
Info.TextYAlignment = Enum.TextYAlignment.Top
Info.TextWrapped = true
Info.TextColor3 = Color3.fromRGB(220,220,220)
Info.Font = Enum.Font.Gotham
Info.Text =
"1. Click JOIN GROUP\n"..
"2. Link will be copied\n"..
"3. Paste link in browser\n"..
"4. Join group and enjoy"
Info.Parent = AccessPanel

local Join = Instance.new("TextButton")
Join.Size = UDim2.new(.7,0,0,60)
Join.Position = UDim2.new(.15,0,.72,0)
Join.BackgroundColor3 = Color3.fromRGB(0,140,255)
Join.Text = "JOIN GROUP"
Join.TextScaled = true
Join.Font = Enum.Font.GothamBold
Join.TextColor3 = Color3.new(1,1,1)
Join.Parent = AccessPanel

Instance.new("UICorner", Join).CornerRadius = UDim.new(1,0)

--------------------------------------------------
-- SEARCH BAR
--------------------------------------------------

local SearchFrame = Instance.new("Frame")
SearchFrame.Size = UDim2.new(1,-20,0,50)
SearchFrame.BackgroundTransparency = 1
SearchFrame.Parent = Scroll

local SearchBox = Instance.new("TextBox")
SearchBox.Size = UDim2.new(1,0,1,0)
SearchBox.PlaceholderText = "Search..."
SearchBox.Text = ""
SearchBox.Parent = SearchFrame

Instance.new("UICorner", SearchBox).CornerRadius = UDim.new(1,0)

--------------------------------------------------
-- GAME GRID
--------------------------------------------------

local GamesContainer = Instance.new("Frame")
GamesContainer.Size = UDim2.new(1,-20,0,600)
GamesContainer.BackgroundTransparency = 1
GamesContainer.Parent = Scroll

local Grid = Instance.new("UIGridLayout")
Grid.CellSize = UDim2.new(0,220,0,150)
Grid.CellPadding = UDim2.new(0,15,0,15)
Grid.Parent = GamesContainer

local Games = {
	{Name="Adopt Me", Image="rbxassetid://0"},
	{Name="Blox Fruits", Image="rbxassetid://0"},
	{Name="MM2", Image="rbxassetid://0"},
	{Name="Doors", Image="rbxassetid://0"},
}

for _,data in ipairs(Games) do
	local Card = Instance.new("Frame")
	Card.BackgroundTransparency = 1
	Card.Parent = GamesContainer

	local Thumb = Instance.new("ImageLabel")
	Thumb.Size = UDim2.new(1,0,.8,0)
	Thumb.BackgroundTransparency = 1
	Thumb.Image = data.Image
	Thumb.Parent = Card

	local Link = Instance.new("TextButton")
	Link.Size = UDim2.new(0,100,0,35)
	Link.Position = UDim2.new(.5,-50,.82,0)
	Link.Text = "🔗"
	Link.Parent = Card

	Instance.new("UICorner", Link).CornerRadius = UDim.new(1,0)
end

--------------------------------------------------
-- AUTO CANVAS
--------------------------------------------------

local function UpdateCanvas()
	task.wait()
	Scroll.CanvasSize = UDim2.new(
		0,
		0,
		0,
		Layout.AbsoluteContentSize.Y + 20
	)
end

Layout:GetPropertyChangedSignal("AbsoluteContentSize"):Connect(UpdateCanvas)
UpdateCanvas()
