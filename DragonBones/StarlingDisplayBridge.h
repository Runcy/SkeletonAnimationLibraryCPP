namespace dragonBones
{
    /**
     * The StarlingDisplayBridge class is an implementation of the IDisplayBridge interface for starling.display.DisplayObject.
     *
     */
    class StarlingDisplayBridge : public IDisplayBridge
    {
        Image *_imageBackup;
        Texture* _textureBackup;
        Number _pivotXBackup;
        Number _pivotYBackup;
        
        Object* _display;
        /**
         * @inheritDoc
         */
        Object *getDisplay()
        {
            return _display;
        }
        void setDisplay(Object *value)
        {
            /*
            if (_display is Image && value is Image)
            {
                var from:Image = _display as Image;
                var to:Image = value as Image;
                if (from.texture == to.texture)
                {
                    if(from == _imageBackup)
                    {
                        from.texture = _textureBackup;
                        from.pivotX = _pivotXBackup;
                        from.pivotY = _pivotYBackup;
                        from.readjustSize();
                    }
                    return;
                }
            
                from.texture = to.texture;
                //update pivot
                from.pivotX = to.pivotX;
                from.pivotY = to.pivotY;
                from.readjustSize();
                return;
            }
            */
            
            if (_display == value)
            {
                return;
            }
            
            if (_display)
            {
                Object parent = _display->parent;
                if (parent)
                {
                    var index:int = _display.parent.getChildIndex(_display);
                }
                removeDisplay();
            }
            /*
            else if(value is Image && !_imageBackup)
            {
                _imageBackup = value as Image;
                _textureBackup = _imageBackup.texture;
                _pivotXBackup = _imageBackup.pivotX;
                _pivotYBackup = _imageBackup.pivotY;
            }
            */
            _display = value;
            addDisplay(parent, index);
        }
        
        public function get visible():Boolean
        {
            return _display?_display.visible:false;
        }
        public function set visible(value:Boolean):void
        {
            if(_display)
            {
                _display.visible = value;
            }
        }
        
        /**
         * Creates a new StarlingDisplayBridge instance.
         */
        public function StarlingDisplayBridge()
        {
        }
        
        /**
         * @inheritDoc
         */
        public function dispose():void
        {
            _display = null;
            _imageBackup = null;
            _textureBackup = null;
        }
        
        /**
         * @inheritDoc
         */
        public function updateTransform(matrix:Matrix, transform:DBTransform):void
        {
            var pivotX:Number = _display.pivotX;
            var pivotY:Number = _display.pivotY;
            matrix.tx -= matrix.a * pivotX + matrix.c * pivotY;
            matrix.ty -= matrix.b * pivotX + matrix.d * pivotY;
            //if(updateStarlingDisplay)
            //{
            //    _display.transformationMatrix = matrix;
            //}
            //else
            //{
                _display.transformationMatrix.copyFrom(matrix);
            //}
        }
        
        /**
         * @inheritDoc
         */
        public function updateColor(
            aOffset:Number, 
            rOffset:Number, 
            gOffset:Number, 
            bOffset:Number, 
            aMultiplier:Number, 
            rMultiplier:Number, 
            gMultiplier:Number, 
            bMultiplier:Number
        ):void
        {
            _display.alpha = aMultiplier;
            if (_display is Quad)
            {
                (_display as Quad).color = (uint(rMultiplier * 0xff) << 16) + (uint(gMultiplier * 0xff) << 8) + uint(bMultiplier * 0xff);
            }
        }
        
        /**
         * @inheritDoc
         */
        public function updateBlendMode(blendMode:String):void
        {
            if (_display is DisplayObject)
            {
                _display.blendMode = blendMode;
            }
        }
        
        /**
         * @inheritDoc
         */
        public function addDisplay(container:Object, index:int = -1):void
        {
            if (container && _display)
            {
                if (index < 0)
                {
                    container.addChild(_display);
                }
                else
                {
                    container.addChildAt(_display, Math.min(index, container.numChildren));
                }
            }
        }
        
        /**
         * @inheritDoc
         */
        public function removeDisplay():void
        {
            if (_display && _display.parent)
            {
                _display.parent.removeChild(_display);
            }
        }
    }
}
